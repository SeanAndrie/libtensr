/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 01:30:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 01:15:15 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_bool	tensr_fill(t_tensr *t, double value)
{
	t_iter	it;
	void	*dst;

	if (!t || !iter_init(&t->layout, &it) || t->dtype == DT_C64
		|| t->dtype == DT_C128)
		return (FALSE);
	while (iter_next(&it))
	{
		dst = tensr_get(t, it.indices);
		if (t->dtype == DT_U8)
			*(uint8_t *)dst = (uint8_t)value;
		else if (t->dtype == DT_I32)
			*(int32_t *)dst = (int32_t)value;
		else if (t->dtype == DT_I64)
			*(int64_t *)dst = (int64_t)value;
		else if (t->dtype == DT_F32)
			*(float *)dst = (float)value;
		else if (t->dtype == DT_F64)
			*(double *)dst = value;
	}
	return (TRUE);
}
