/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 01:24:33 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/14 01:46:33 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr_ctx.h>

void    *tensr_malloc(const size_t bytes)
{
    if (!ctx)
        return (malloc(bytes));
    return (harena_alloc(ctx->forward, bytes));
}
