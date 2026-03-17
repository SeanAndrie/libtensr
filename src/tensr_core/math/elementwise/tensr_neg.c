/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:52:01 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/06 01:38:43 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>
#include <tensr_core/core_math.h>

t_tensr	*tensr_neg(const t_tensr *t)
{
	t_iter	it;
	t_tensr	*out;
	void	*src;
	void	*dst;

	out = tensr_alloc(t->layout.ndim, t->layout.shape, t->dtype);
	if (!out)
		return (NULL);
	if (!iter_init(&out->layout, &it))
		return (tensr_free(out), NULL);
	while (iter_next(&it))
	{
		src = tensr_get(t, it.indices);
		dst = tensr_get(out, it.indices);
		if (out->dtype == DT_U8)
			*(uint8_t *)dst = *(uint8_t *)src;
		else if (out->dtype == DT_I32)
			*(int32_t *)dst = -(*(int32_t *)src);
		else if (out->dtype == DT_I64)
			*(int64_t *)dst = -(*(int64_t *)src);
		else if (out->dtype == DT_F32)
			*(float *)dst = -(*(float *)src);
		else if (out->dtype == DT_F64)
			*(double *)dst = -(*(double *)src);
	}
	return (out);
}
