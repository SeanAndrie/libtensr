/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:26:29 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/27 17:55:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

bool    layout_copy(t_layout *dst, const t_layout *src)
{
    int i;

    if (!dst || !src || src->ndim == 0)
        return (false);
    layout_free(dst);
    if (!layout_alloc(src->ndim, dst))
        return (false);
    i = 0;
    while (i < src->ndim)
    {
        dst->shape[i] = src->shape[i];
        dst->stride[i] = src->stride[i];
        i++;
    }
    return (true);
}
