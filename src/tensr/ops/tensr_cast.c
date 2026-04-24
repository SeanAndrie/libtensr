/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:20:57 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 19:54:03 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

static double complex	cast_to_complex(void *src, t_dtype src_type)
{
	if (src_type == DT_U8)
		return ((double complex) * (uint8_t *)src);
	else if (src_type == DT_I32)
		return ((double complex) * (int32_t *)src);
	else if (src_type == DT_I64)
		return ((double complex) * (int64_t *)src);
	else if (src_type == DT_F32)
		return ((double complex) * (float *)src);
	else if (src_type == DT_F64)
		return ((double complex) * (double *)src);
	else if (src_type == DT_C64)
		return ((double complex) * (float complex *)src);
	return (*(double complex *)src);
}

static void	cast_from_complex(void *dst, double complex val, t_dtype dst_type)
{
	if (dst_type == DT_U8)
		*(uint8_t *)dst = (uint8_t)creal(val);
	else if (dst_type == DT_I32)
		*(int32_t *)dst = (int32_t)creal(val);
	else if (dst_type == DT_I64)
		*(int64_t *)dst = (int64_t)creal(val);
	else if (dst_type == DT_F32)
		*(float *)dst = (float)creal(val);
	else if (dst_type == DT_F64)
		*(double *)dst = creal(val);
	else if (dst_type == DT_C64)
		*(float complex *)dst = (float complex)val;
	else
		*(double complex *)dst = val;
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
	t_bool	alloc;

	alloc = FALSE;
	if (out)
		ret = out;
	else
	{
		ret = tensr_alloc(t->layout.ndim, t->layout.shape, t->dtype);
		if (!ret)
			return (NULL);
		alloc = TRUE;
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
	t_iter			it;
	double complex	value;

	if (!t)
		return (NULL);
	if (t->dtype == dtype)
		return (cast_same_dtype(t, out));
	out = initialize(t, out, &it);
	if (!out)
		return (NULL);
	while (iter_next(&it))
	{
		value = cast_to_complex(tensr_get(t, it.indices), t->dtype);
		cast_from_complex(tensr_get(out, it.indices), value, out->dtype);
	}
	return (out);
}
