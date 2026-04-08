/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:38:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 21:39:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/core.h>

size_t  tensr_offset(const t_layout *l, const size_t *indices)
{
    int     i;
    size_t  offset;
    
    if (!l || !indices)
        return ((size_t)-1);
    i = 0;
    offset = 0;
    while (i < l->ndim)
    {
        if (indices[i] >= l->shape[i])
            return ((size_t)-1);
        offset += indices[i] * l->stride[i];
        i++;
    }
    return (offset);
}
