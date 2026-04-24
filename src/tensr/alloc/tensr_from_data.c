/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_from_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:36:53 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 22:57:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

static t_array	create_array(void *data, const size_t len, t_dtype dtype)
{
	t_array	arr;

	ft_memset(&arr, 0, sizeof(t_array));
	if (dtype == DT_U8)
		arr = arr_u8((uint8_t *)data, len);
	else if (dtype == DT_I32)
		arr = arr_i32((int32_t *)data, len);
	else if (dtype == DT_I64)
		arr = arr_i64((int64_t *)data, len);
	else if (dtype == DT_F32)
		arr = arr_f32((float *)data, len);
	else if (dtype == DT_F64)
		arr = arr_f64((double *)data, len);
	else if (dtype == DT_C64)
		arr = arr_c64((float complex *)data, len);
	else if (dtype == DT_C128)
		arr = arr_c128((double complex *)data, len);
	return (arr);
}

t_tensr	*tensr_from_data(void *data, const int ndim, const size_t *shape,
		t_dtype dtype)
{
	t_tensr	*t;
	t_array	arr;

	if (!data)
		return (NULL);
	if (!(dtype == DT_U8 || dtype == DT_I32 || dtype == DT_I64
			|| dtype == DT_F32 || dtype == DT_F64 || dtype == DT_C64
			|| dtype == DT_C128))
		return (NULL);
	t = tensr_alloc(ndim, shape, dtype);
	if (!t)
		return (NULL);
	arr = create_array(data, t->size, dtype);
	if (arr.len == 0)
	{
		tensr_free(t);
		return (NULL);
	}
	ft_memcpy(t->data, arr.data, t->elemsize * t->size);
	return (t);
}
