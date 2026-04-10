/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:00:34 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/29 22:58:22 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_debug.h>

static size_t	dtype_size_in_bytes(t_dtype dtype)
{
	if (dtype == DT_U8)
		return (1);
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

t_tensr	*tensr_alloc(const int ndim, const size_t *shape, t_dtype dtype)
{
	t_tensr	*t;

	if (invalid_parameters(ndim, shape))
		return (NULL);
	t = malloc(sizeof(t_tensr));
	if (!t)
		return (NULL);
	t->dtype = dtype;
	t->owns_data = true;
	t->elemsize = dtype_size_in_bytes(dtype);
	if (t->elemsize == 0)
		return (free(t), NULL);
	t->size = layout_init(&t->layout, ndim, shape);
	t->data = malloc(t->elemsize * t->size);
	if (!t->data)
		return (tensr_free(t), NULL);
	return (t);
}
