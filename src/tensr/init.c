/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:22:02 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/07 16:03:16 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>

void    free_tensr(t_tensr *tensr)
{
    if (!tensr)
        return ;
    if (tensr->data)
        free(tensr->data);
    if (tensr->shape)
        free(tensr->shape);
    if (tensr->stride)
        free(tensr->stride);
    free(tensr);
}

static t_tensr *tensr_init(size_t ndim, size_t itemsize)
{
    t_tensr    *tensr;

    if (ndim == 0 || itemsize == 0)
        return (NULL);
    tensr = malloc(sizeof(t_tensr));
    if (!tensr)
        return (NULL);
    tensr->ndim = ndim;
    tensr->itemsize = itemsize;
    tensr->size = 1;
    tensr->data = NULL;
    tensr->shape = NULL;
    tensr->stride = NULL;
    return (tensr);
}

static bool calculate_stride(t_tensr *t)
{
    size_t  i;

    if (!t|| !t->shape)
        return (false);
    t->stride = malloc(sizeof(size_t) * t->ndim);
    if (!t->stride)
        return (false);
    t->stride[t->ndim - 1] = t->itemsize;
    i = t->ndim;
    while (i-- > 1)
        t->stride[i - 1] = t->stride[i] * t->shape[i];
    return (true);
}

static bool init_metadata(t_tensr *t, va_list dims)
{
    size_t  i;
    size_t  dim;

    if (!t)
        return (false);
    t->shape = malloc(sizeof(size_t) * t->ndim);
    if (!t->shape)
        return (false);
    i = 0;
    while (i < t->ndim)
    {
        dim = va_arg(dims, size_t);
        if (dim == 0 || t->size > __SIZE_MAX__ / dim)
        {
            free(t->shape);
            return (false);
        }
        t->shape[i] = dim;
        t->size *= dim;
        i++;
    }
    if (!calculate_stride(t))
        return (false);
    return (true);
}

t_tensr    *tensr_create(const size_t ndim, const size_t itemsize, ...)
{
    t_tensr    *t;
    va_list     dims;

    t= tensr_init(ndim, itemsize);
    if (!t)
        return (NULL);
    va_start(dims, itemsize);
    if (!init_metadata(t, dims))
    {
        va_end(dims);
        return (free_tensr(t), NULL);
    }
    va_end(dims);
    if (t->size > __SIZE_MAX__ / t->itemsize)
        return (free_tensr(t), NULL);
    t->data = malloc(t->size * t->itemsize);
    if (!t->data)
        return (free_tensr(t), NULL);
    return (t);
}
