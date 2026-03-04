/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_from_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:33:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/17 15:38:00 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

t_tensr	*tensr_from_arr(const t_array *arr, const int ndim, const size_t *shape,
		t_dtype dtype)
{
	t_tensr	*t;

	if (!arr || arr->len == 0 || arr->dtype != dtype)
		return (NULL);
	t = tensr_alloc(ndim, shape, dtype);
	if (!t || t->size != arr->len)
		return (NULL);
	ft_memcpy(t->data, arr->data, t->elemsize * t->size);
	return (t);
}
