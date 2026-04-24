/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reduce_ctx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 01:50:09 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 01:58:49 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_math.h>

t_reduce_ctx	*tensr_reduce_ctx(const int n_axes, const size_t *axes,
		t_reduce_op op)
{
	int				i;
	t_reduce_ctx	*ctx;

	ctx = malloc(sizeof(t_reduce_ctx));
	if (!ctx)
		return (NULL);
	ft_memset(&ctx->is_reduced, 0, sizeof(ctx->is_reduced));
	i = 0;
	while (i < n_axes)
		ctx->is_reduced[axes[i++]] = TRUE;
	ctx->base_off = 0;
	ctx->reduce_op = op;
	return (ctx);
}
