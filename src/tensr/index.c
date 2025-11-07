/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:35:21 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/06 23:38:43 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr.h>

static size_t tensr_offset(const t_tensr *t, const size_t *indices)
{
    size_t  i;
    size_t  offset;

    i = 0;
    while (i++ < t->ndim)
        offset += indices[i] * t->stride[i];
    return (offset);
}

void    tensr_set(const t_tensr *t, const size_t *indices, void *value)
{
    unsigned char *base;

    if (!t || !indices)
        return ;
    base = (unsigned char *)t->data + tensr_set(t, indices);
    ft_memcpy(value, base, t->itemsize);
}

void    tensr_get(const t_tensr *t, const size_t *indices, void *value)
{
    unsigned char *base;

    if (!t || !indices)
        return ;
    base = (unsigned char *)t->data + tensr_offset(t, indices);
    ft_memcpy(value, base, t->itemsize);
}
