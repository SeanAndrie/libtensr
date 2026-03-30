/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:20:57 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 14:20:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

static double	cast_to_double(void *src, t_dtype src_type)
{
	if (src_type == DT_U8)
		return ((double)*(uint8_t *)src);
	if (src_type == DT_I32)
		return ((double)*(int32_t *)src);
	if (src_type == DT_I64)
		return ((double)*(int64_t *)src);
	if (src_type == DT_F32)
		return ((double)*(float *)src);
	return (*(double *)src);
}

static void	cast_from_double(void *dst, double val, t_dtype dst_type)
{
	if (dst_type == DT_U8)
		*(uint8_t *)dst = (uint8_t)val;
	else if (dst_type == DT_I32)
		*(int32_t *)dst = (int32_t)val;
	else if (dst_type == DT_I64)
		*(int64_t *)dst = (int64_t)val;
	else if (dst_type == DT_F32)
		*(float *)dst = (float)val;
	else
		*(double *)dst = val;
}

static t_tensr	*tensr_out(t_tensr *out, const t_tensr *t, t_dtype dtype)
{
	if (out)
		return (out);
	return (tensr_alloc(t->layout.ndim, t->layout.shape, dtype));
}

static t_tensr	*cast_same_dtype(const t_tensr *t, t_tensr *out)
{
	if (out)
	{
		if (!layout_equal(&t->layout, &out->layout))
			return (NULL);
		ft_memcpy(out->data, t->data, t->elemsize * t->size);
		return (out);
	}
	return (tensr_copy(t));
}

t_tensr	*tensr_cast(const t_tensr *t, t_dtype dtype, t_tensr *out)
{
	t_iter	it;
	bool	alloced;

	if (!t)
		return (NULL);
	if (t->dtype == dtype)
		return (cast_same_dtype(t, out));
	alloced = (out == NULL);
	out = tensr_out(out, t, dtype);
	if (!out)
		return (NULL);
	if (!iter_init(&out->layout, &it))
	{
		if (alloced)
			tensr_free(out);
		return (NULL);
	}
	while (iter_next(&it))
		cast_from_double(tensr_get(out, it.indices), cast_to_double(tensr_get(t,
					it.indices), t->dtype), dtype);
	return (out);
}
