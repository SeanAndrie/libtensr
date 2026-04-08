/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 22:42:08 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/29 22:57:36 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

size_t  layout_init(t_layout *l, const int ndim, const size_t *shape)
{
    int         i;
    size_t      size;
    
    size = 1;
    if (!layout_alloc(ndim, l) || ndim == 0)
        return (size);
    i = 0;
    while (i < ndim)
    {
        l->shape[i] = shape[i];
        size *= shape[i];
        i++;
    }
    l->stride[l->ndim - 1] = 1;
    i = l->ndim - 2;
    while (i >= 0)
    {
        l->stride[i] = l->stride[i + 1] * l->shape[i + 1];
        i--;
    }
    return (size);
}
