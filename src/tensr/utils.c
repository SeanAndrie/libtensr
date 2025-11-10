/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:46:11 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/10 17:54:07 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>

void    free_tensr(t_tensr *t)
{
    if (!t)
        return ;
    if (t->data)
        free(t->data);
    if (t->shape)
        free(t->shape);
    if (t->stride)
        free(t->stride);
    free(t);
}

size_t tensr_offset(const t_tensr *t, const size_t *indices)
{
    size_t  i;
    size_t  offset;

    i = 0;
    offset = 0;
    while (i < t->ndim)
    {
        offset += indices[i] * t->stride[i];
        i++;
    }
    return (offset);
}
