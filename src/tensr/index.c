/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:35:21 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/07 16:03:18 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>

static bool indices_in_bounds(const t_tensr *t, const size_t *indices)
{
    size_t  i;

    i = 0;
    while (i < t->ndim)
    {
        if (indices[i] >= t->shape[i])
            return (false);
        i++;
    }
    return (true);
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

bool    tensr_set(t_tensr *t, const size_t *indices, void *value)
{
    unsigned char   *base;
    size_t          value_size;

    if (!t || !indices || !value || !t->data)
        return (false);
    if (!indices_in_bounds(t, indices))
        return (false);
    base = (unsigned char *)t->data + tensr_offset(t, indices);
    ft_memcpy(base, value, t->itemsize);
    return (true);
}

bool    tensr_get(t_tensr *t, const size_t *indices, void *value)
{
    unsigned char *base;

    if (!t || !indices || !value || !t->data)
        return (false);
    if (!indices_in_bounds(t, indices))
        return (false);
    base = (unsigned char *)t->data + tensr_offset(t, indices);
    ft_memcpy(value, base, t->itemsize);
    return (true);
}
