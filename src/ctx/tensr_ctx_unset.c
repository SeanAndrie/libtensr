/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_ctx_unset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:55:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/13 19:59:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

void    tensr_ctx_unset(void)
{
    if (ctx->scratch)
        harena_free(ctx->scratch);
    if (ctx->forward)
        harena_free(ctx->forward);
    if (ctx->graph)
        harena_free(ctx->graph);
    free(ctx);
}
