/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reduce_strided.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 00:14:30 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/07 02:32:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

static void	create_reduce_ctx(t_reduce_ctx *ctx, const t_tensr *src,
		const int n_axes, const size_t *axes)
{
	int	i;
	int	j;

	ft_memset(ctx, 0, sizeof(t_reduce_ctx));
	i = 0;
	while (i < n_axes)
		ctx->is_reduced[axes[i++]] = true;
	i = -1;
	j = 0;
	ctx->reduced_l.shape = ctx->reduced_shape;
	ctx->reduced_l.stride = ctx->reduced_stride;
	while (++i < src->layout.ndim)
	{
		if (ctx->is_reduced[i])
		{
			ctx->reduced_l.shape[j] = src->layout.shape[i];
			ctx->reduced_l.stride[j] = src->layout.stride[i];
			j++;
		}
	}
	ctx->src = src;
	ctx->reduced_l.ndim = j;
}

static size_t	calculate_base_offset(const t_layout *src_l,
		const size_t *outer_indices, const bool *is_reduced)
{
	int		i;
	int		j;
	size_t	offset;

	i = 0;
	j = 0;
	offset = 0;
	while (i < src_l->ndim)
	{
		if (!is_reduced[i])
			offset += outer_indices[j++] * src_l->stride[i];
		i++;
	}
	return (offset);
}

static void	apply_reduction(void *accum, size_t base_offset, t_reduce_ctx *ctx,
		t_iter *inner)
{
	size_t	offset;
	void	*value;

	iter_reset(inner);
    // Iterate over non-reduced dimensions
	while (iter_next(inner))
	{
		offset = tensr_offset(&ctx->reduced_l, inner->indices) + base_offset;
		value = (char *)ctx->src->data + offset * ctx->src->elemsize;
		ctx->reduce_op.apply(accum, value, ctx->src->dtype);
	}
    if (ctx->reduce_op.finalize)
	    ctx->reduce_op.finalize(accum, inner->total, ctx->src->dtype);
}

t_tensr	*tensr_reduce_strided(const t_tensr *t, const int n_axes,
		const size_t *axes, t_reduce_op op)
{
	t_reduce_ctx	ctx;
	t_iter			outer;
	t_iter			inner;
	size_t			offset;
	unsigned char	acc[MAX_ACC_SIZE];

	create_reduce_ctx(&ctx, t, n_axes, axes);
	// 1. Allocate reduced tensor
	ctx.dst = tensr_reduced(&t->layout, n_axes, axes, t->dtype);
	if (!ctx.dst)
		return (NULL);
	ctx.reduce_op = op;
	// 2. Initialize outer and inner iterators
	// For inner iterator, create a view with reduced layout pointing to src data
	if (!iter_init(&ctx.dst->layout, &outer))
		return (tensr_free(ctx.dst), NULL);
	tensr_view(ctx.src, ctx.src->data, &ctx.reduced_l);
	if (!iter_init(&ctx.reduced_l, &inner))
		return (tensr_free(ctx.dst), NULL);
	// 3. Iterate over reduced dimensions
	while (iter_next(&outer))
	{
		ctx.reduce_op.init(acc, ctx.src->dtype);
		offset = calculate_base_offset(&t->layout, outer.indices,
				ctx.is_reduced);
		apply_reduction(acc, offset, &ctx, &inner);
		tensr_set(ctx.dst, acc, outer.indices);
	}
	return (ctx.dst);
}
