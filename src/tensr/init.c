/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:22:02 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/10 17:55:15 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tensr.h>

void    free_tensr(t_tensr *t) {
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

static t_tensr *tensr_init(size_t ndim, t_dtype type)
{
    t_tensr *t;

    t = malloc(sizeof(t_tensr));
    if (!t)
        return (NULL);
    t->ndim = ndim;
    t->dtype = type;
    if (t->dtype == DTYPE_INT)
        t->itemsize = sizeof(int);
    else if (t->dtype == DTYPE_FLOAT)
        t->itemsize = sizeof(float);
    else if (t->dtype == DTYPE_DOUBLE)
        t->itemsize = sizeof(double);
    t->size = 1;
    t->data = NULL;
    t->shape = NULL;
    t->stride = NULL;
    return (t);
}

static bool calculate_stride(t_tensr *t)
{
    size_t  i;

    if (!t || !t->shape)
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

static bool init_metadata(t_tensr *t, const size_t *shape)
{
    size_t i;
    size_t dim;

    if (!t || !shape)
        return (false);
    t->shape = malloc(sizeof(size_t) * t->ndim);
    if (!t->shape)
        return (false);
    i = 0;
    while (i < t->ndim)
    {
        dim = shape[i];
        if (dim == 0 || t->size > __SIZE_MAX__ / dim)
        {
            free(t->shape);
            t->shape = NULL;
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

t_tensr *tensr_create(const size_t ndim, const size_t *shape, t_dtype dtype)
{
    t_tensr *t;

    if (!shape)
        return (NULL);
    if (ndim == 0)
        t = tensr_init(1, dtype);
    else
        t = tensr_init(ndim, dtype);
    if (!t)
        return (NULL);
    if (!init_metadata(t, shape))
        return (free_tensr(t), NULL);
    if (t->size > __SIZE_MAX__ / t->itemsize)
        return (free_tensr(t), NULL);
    t->data = ft_calloc(t->size, t->itemsize);
    if (!t->data)
        return (free_tensr(t), NULL);
    return (t);
}
