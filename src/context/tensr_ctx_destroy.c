/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_ctx_unset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:55:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/14 01:40:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr_ctx.h>

void    tensr_ctx_destroy(void)
{
    if (!ctx)
        return ;
    harena_free(ctx->scratch);
    harena_free(ctx->forward);
    harena_free(ctx->graph);
    free(ctx);
    ctx = NULL;
}
