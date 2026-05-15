/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_ctx_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:43:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/14 02:18:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr_ctx.h>

_Thread_local t_tensr_ctx *ctx = NULL;

t_bool	tensr_ctx_set(const size_t graph_size, const size_t forward_size,
            const size_t scratch_size)
{
    if (ctx)
        tensr_ctx_destroy();
    ctx = malloc(sizeof(t_tensr_ctx));
    if (!ctx)
        return (FALSE);
    ctx->scratch = NULL;
    ctx->no_grad = FALSE;
    ctx->graph = harena_create(graph_size);
    ctx->forward = harena_create(forward_size);
    if (scratch_size > 0)
        ctx->scratch = harena_create(scratch_size);
    if (!ctx->graph || !ctx->forward || (scratch_size > 0 && !ctx->scratch))
    {
        tensr_ctx_destroy();
        return (FALSE);
    }
    return (TRUE);
}
