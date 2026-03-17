/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:38:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/17 17:15:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

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

// size_t	tensr_offset(const t_tensr *t, const size_t *indices)
// {
// 	int		    i;
//     t_layout    l;
// 	size_t	offset;
//
// 	if (!t || !indices)
// 		return ((size_t)-1);
// 	i = 0;
// 	offset = 0;
//     l = t->layout;
// 	while (i < l.ndim)
// 	{
// 		if (indices[i] >= l.shape[i])
// 			return ((size_t)-1);
// 		offset += indices[i] * l.stride[i];
// 		i++;
// 	}
// 	return (offset);
// }
