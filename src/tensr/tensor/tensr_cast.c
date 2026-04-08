/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:20:57 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/01 23:34:56 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/core.h>

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

static t_tensr	*initialize(const t_tensr *t, t_tensr *out, t_iter *it)
{
	t_tensr	*ret;
	bool	alloc;

    alloc = false;
	if (out)
		ret = out;
	else
	{
		ret = tensr_alloc(t->layout.ndim, t->layout.shape, t->dtype);
		if (!ret)
			return (NULL);
		alloc = true;
	}
	if (!iter_init(&ret->layout, it))
	{
		if (alloc)
			tensr_free(ret);
		return (NULL);
	}
	return (ret);
}

t_tensr	*tensr_cast(const t_tensr *t, t_dtype dtype, t_tensr *out)
{
	t_iter	it;
	float	value;

	if (!t)
		return (NULL);
	if (t->dtype == dtype)
		return (cast_same_dtype(t, out));
	out = initialize(t, out, &it);
	if (!out)
		return (NULL);
	while (iter_next(&it))
	{
		value = cast_to_double(tensr_get(t, it.indices), t->dtype);
		cast_from_double(tensr_get(out, it.indices), value, out->dtype);
	}
	return (out);
}
