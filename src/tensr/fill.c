/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:41:30 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/13 13:09:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tensr.h>

t_tensr *tensr_full(const size_t ndim, size_t *shape, t_dtype dtype, void *value)
{
    size_t      i;
    t_tensr     *out;
    size_t      indices[MAX_NDIM];

    if (ndim == 0 || !shape || !value)
        return (NULL);
    out = tensr_create(ndim, shape, dtype);
    if (!out)
        return (NULL);
    ft_memset(indices, 0, sizeof(indices));
    i = 0;
    while (i < out->size)
    {
        if (!tensr_set(out, out->ndim, indices, value))
            return (free_tensr(out), NULL);
        next_coords(indices, out->shape, out->ndim);
        i++;
    }
    return (out);
}

