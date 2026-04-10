/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reduce_strided.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:14:30 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 20:59:04 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

static size_t	calculate_base_offset(const t_layout *l,
		const size_t *outer_indices, const t_bool *is_reduced)
{
	int		i;
	int		j;
	size_t	offset;

	i = 0;
	j = 0;
	offset = 0;
	while (i < l->ndim)
	{
		if (!is_reduced[i])
			offset += outer_indices[j++] * l->stride[i];
		i++;
	}
	return (offset);
}

static void	apply_reduction(const t_tensr *t, void *accum, t_reduce_ctx *ctx)
{
	size_t	offset;
	void	*value;

	iter_reset(&ctx->inner);
	while (iter_next(&ctx->inner))
	{
		offset = tensr_offset(&ctx->reduced_l, ctx->inner.indices)
			+ ctx->base_off;
		value = (char *)t->data + offset * t->elemsize;
		ctx->reduce_op.apply(accum, value, t->dtype);
	}
	if (ctx->reduce_op.finalize)
		ctx->reduce_op.finalize(accum, ctx->inner.total, t->dtype);
}

static t_layout	layout_reduced(const t_layout *l, const t_bool *is_reduced)
{
	int			i;
	int			j;
	t_layout	reduced_l;

	j = 0;
	i = -1;
	ft_memset(&reduced_l, 0, sizeof(t_layout));
	reduced_l.shape = reduced_l.shape_buf;
	reduced_l.stride = reduced_l.stride_buf;
	while (++i < l->ndim)
	{
		if (!is_reduced[i])
			continue ;
		reduced_l.shape[j] = l->shape[i];
		reduced_l.stride[j] = l->stride[i];
		j++;
	}
	reduced_l.ndim = j;
	return (reduced_l);
}

t_tensr	*tensr_reduce_strided(const t_tensr *t, const int n_axes,
		const size_t *axes, t_reduce_ctx *ctx)
{
	t_tensr			*out;
	unsigned char	acc[MAX_ACC_SIZE];

	if (n_axes <= 0 || !t || !axes)
		return (NULL);
	out = tensr_reduced(t, n_axes, ctx->is_reduced);
	if (!out)
		return (NULL);
	iter_init(&out->layout, &ctx->outer);
	ctx->reduced_l = layout_reduced(&t->layout, ctx->is_reduced);
	iter_init(&ctx->reduced_l, &ctx->inner);
	while (iter_next(&ctx->outer))
	{
		ctx->reduce_op.init(acc, t->dtype);
		ctx->base_off = calculate_base_offset(&t->layout, ctx->outer.indices,
				ctx->is_reduced);
		apply_reduction(t, &acc, ctx);
		tensr_set(out, acc, ctx->outer.indices);
	}
	return (out);
}
