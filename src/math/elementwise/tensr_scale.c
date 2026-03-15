/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 21:23:42 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/15 21:45:47 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>

t_tensr	*tensr_scale(const t_tensr *t, double value)
{
	t_iter	it;
	t_tensr	*out;
	void	*src;
	void	*dst;

	out = tensr_alloc(t->layout.ndim, t->layout.shape, t->dtype);
	if (!out || !iter_init(&out->layout, &it))
		return (tensr_free(out), NULL);
	while (iter_next(&it))
	{
		src = tensr_get(t, it.indices);
		dst = tensr_get(out, it.indices);
		if (t->dtype == DT_U8)
			*(uint8_t *)dst = *(uint8_t *)src * (uint8_t)value;
		else if (t->dtype == DT_I32)
			*(int32_t *)dst = *(int32_t *)src * (int32_t)value;
		else if (t->dtype == DT_I64)
			*(int64_t *)dst = *(int64_t *)src * (int64_t)value;
		else if (t->dtype == DT_F32)
			*(float *)dst = *(float *)src * (float)value;
		else if (t->dtype == DT_F64)
			*(double *)dst = *(double *)src * value;
	}
	return (out);
}
