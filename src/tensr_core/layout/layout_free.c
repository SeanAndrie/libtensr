/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 23:59:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 00:16:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

void    layout_free(t_layout *l)
{
    if (!l)
        return ;
    if (l->ndim >= MIN_NDIM)
    {
        if (l->shape)
        {
            free(l->shape);
            l->shape = NULL;
        }
        if (l->stride)
        {
            free(l->stride);
            l->stride = NULL;
        }
    }
    else
        ft_memset(l, 0, sizeof(t_layout));
    l->ndim = 0;
}
