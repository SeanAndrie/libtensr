/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:00:34 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/27 15:41:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

static size_t	dtype_size_in_bytes(t_dtype dtype)
{
	if (dtype == DT_I32 || dtype == DT_F32)
		return (4);
	else if (dtype == DT_I64 || dtype == DT_F64)
		return (8);
	return (0);
}

static bool	invalid_parameters(const int ndim, const size_t *shape)
{
	return (ndim < 0 || (ndim > 0 && !shape) || (ndim == 0 && shape)
		|| (ndim > MAX_NDIM));
}

static bool	init_layout(const int ndim, const size_t *shape, t_tensr *dst)
{
	int	        i;
    t_layout    *l;

    l = &dst->layout;
	if (!layout_alloc(ndim, l))
		return (false);
	i = 0;
	while (i < l->ndim)
	{
		l->shape[i] = shape[i];
		dst->size *= shape[i];
		i++;
	}
	l->stride[l->ndim - 1] = 1;
	i = l->ndim - 2;
	while (i >= 0)
	{
		l->stride[i] = l->stride[i + 1] * l->shape[i + 1];
		i--;
	}
	return (true);
}

t_tensr	*tensr_alloc(const int ndim, const size_t *shape, t_dtype dtype)
{
	t_tensr	*t;

	if (invalid_parameters(ndim, shape))
		return (NULL);
	t = malloc(sizeof(t_tensr));
	if (!t)
		return (NULL);
	t->size = 1;
	t->dtype = dtype;
	t->owns_data = true;
	t->elemsize = dtype_size_in_bytes(dtype);
	if (t->elemsize == 0)
		return (free(t), NULL);
	if (ndim > 0 && !init_layout(ndim, shape, t))
		return (tensr_free(t), NULL);
	t->data = malloc(t->elemsize * t->size);
	if (!t->data)
		return (tensr_free(t), NULL);
	return (t);
}
