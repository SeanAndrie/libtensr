/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_ctx_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 01:38:45 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/14 01:55:09 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr_ctx.h>

void    tensr_ctx_reset(void)
{
    if (!ctx)
        return ;
    harena_reset(ctx->graph);
    harena_reset(ctx->forward);
    harena_reset(ctx->scratch);
}
