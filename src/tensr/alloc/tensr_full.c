/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_full.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 02:57:54 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/14 03:07:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

t_tensr	*tensr_full(double value, const int ndim, const size_t *shape,
		t_dtype dtype)
{
	t_iter	it;
	t_tensr	*t;
	void	*dst;

	if (!shape || ndim < 0)
		return (NULL);
	t = tensr_alloc(ndim, shape, dtype);
	if (!t || !iter_init(&t->layout, &it))
		return (tensr_free(t), NULL);
	while (iter_next(&it))
	{
		dst = tensr_get(t, it.indices);
		if (dtype == DT_U8)
			*(uint8_t *)dst = (uint8_t)value;
		else if (dtype == DT_I32)
			*(int32_t *)dst = (int32_t)value;
		else if (dtype == DT_I64)
			*(int64_t *)dst = (int64_t)value;
		else if (dtype == DT_F32)
			*(float *)dst = (float)value;
		else if (dtype == DT_F64)
			*(double *)dst = value;
	}
	return (t);
}
