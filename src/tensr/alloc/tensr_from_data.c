/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_from_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:33:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 18:50:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr	*tensr_from_data(void *data, const int ndim, const size_t *shape,
		t_dtype dtype)
{
	t_tensr	*t;
	t_array	arr;

	if (!data || ndim <= 0 || !shape)
		return (NULL);
	t = tensr_alloc(ndim, shape, dtype);
	if (!t)
		return (NULL);
	if (t->dtype == DT_I32)
		arr = arr_i32(data, t->size);
	else if (t->dtype == DT_I64)
		arr = arr_i64(data, t->size);
	else if (t->dtype == DT_F32)
		arr = arr_f32(data, t->size);
	else if (t->dtype == DT_F64)
		arr = arr_f64(data, t->size);
	ft_memcpy(t->data, arr.data, t->elemsize * t->size);
	return (t);
}
