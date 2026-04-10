/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:32:56 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/18 01:47:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

static t_reduce_ctx *reduce_ctx_init(const int n_axes, const size_t *axes, t_reduce_op op)
{
    int         i;
    t_reduce_ctx *ctx;

    ctx = malloc(sizeof(t_reduce_ctx));
    if (!ctx)
        return (NULL);
    i = 0;
    ft_memset(&ctx->is_reduced, 0, sizeof(ctx->is_reduced));
    while (i < n_axes)
        ctx->is_reduced[axes[i++]] = TRUE;
    ctx->base_off = 0;
    ctx->reduce_op = op;
    return (ctx);
}

t_tensr	*tensr_reduce(const t_tensr *t, const int n_axes, const size_t *axes,
		t_reduce_op op)
{
    t_tensr         *out;
    t_reduce_ctx    *ctx;

	if (!t || !axes || n_axes <= 0)
		return (NULL);
    ctx = reduce_ctx_init(n_axes, axes, op);
    if (!ctx)
        return (NULL);
    out = tensr_reduce_strided(t, n_axes, axes, ctx);
    free(ctx);
    return (out);
}
