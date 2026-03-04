/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:14:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/27 15:37:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

bool layout_alloc(const int ndim, t_layout *l)
{
    if (!l || ndim == 0)
        return (false);
    ft_memset(l, 0, sizeof(t_layout));
    l->ndim = ndim;
    if (ndim >= MIN_NDIM)
    {
        l->shape = malloc(sizeof(size_t) * l->ndim);
        if (!l->shape)
            return (false);
        l->stride = malloc(sizeof(size_t) * l->ndim);
        if (!l->stride)
            return (free(l->shape), false);
    }
    else
    {
        l->shape = l->shape_buf;
        l->stride = l->stride_buf;
    }
    return (true);
}
