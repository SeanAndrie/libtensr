/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:06:55 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 02:44:56 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr_math.h>

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

static void	apply_reduction(const t_tensr *t, t_argcc *arg, t_reduce_ctx *ctx,
		t_bool (*cmp)(const void *a, const void *b, t_dtype dtype))
{
	size_t	offset;
	void	*value;

	iter_reset(&ctx->inner);
	while (iter_next(&ctx->inner))
	{
		offset = tensr_offset(&ctx->reduced_l, ctx->inner.indices)
			+ ctx->base_off;
		value = (char *)t->data + offset * t->elemsize;
		if (!arg->value || !cmp(arg->value, value, t->dtype))
		{
			arg->value = value;
			arg->idx = (int64_t)(ctx->inner.counter - 1);
		}
	}
}

t_tensr	*tensr_arg(const t_tensr *t, const int n_axes, const size_t *axes,
		t_bool (*cmp)(const void *a, const void *b, t_dtype dtype))
{
	t_argcc			arg;
	t_reduce_ctx	*ctx;
	t_tensr			*out;

	if (!t || !axes || n_axes <= 0 || !cmp || t->dtype == DT_C64
		|| t->dtype == DT_C128)
		return (NULL);
	ctx = tensr_reduce_ctx(n_axes, axes, (t_reduce_op){NULL});
	if (!ctx)
		return (NULL);
	out = tensr_reduced(t, 1, ctx->is_reduced, DT_I64);
	if (!out || !iter_init(&out->layout, &ctx->outer))
		return (free(ctx), tensr_free(out), NULL);
	ctx->reduced_l = layout_reduced(&t->layout, ctx->is_reduced);
	iter_init(&ctx->reduced_l, &ctx->inner);
	while (iter_next(&ctx->outer))
	{
		ft_memset(&arg, 0, sizeof(t_argcc));
		ctx->base_off = calculate_base_offset(&t->layout, ctx->outer.indices,
				ctx->is_reduced);
		apply_reduction(t, &arg, ctx, cmp);
		*(int64_t *)tensr_get(out, ctx->outer.indices) = arg.idx;
	}
	return (free(ctx), out);
}
