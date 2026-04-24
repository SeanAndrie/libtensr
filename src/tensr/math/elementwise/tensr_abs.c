/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_abs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:35:54 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 00:29:06 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <tensr/tensr.h>

static t_dtype	convert_dtype(t_dtype dtype)
{
	if (dtype == DT_C64)
		return (DT_F32);
	if (dtype == DT_C128)
		return (DT_F64);
	return (dtype);
}

static t_tensr	*initialize(const t_tensr *t, t_tensr *out, t_iter *it)
{
	t_tensr	*ret;
	t_bool	alloc;

	alloc = false;
	if (out)
		ret = out;
	else
	{
		ret = tensr_alloc(t->layout.ndim, t->layout.shape,
				convert_dtype(t->dtype));
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

static void	assign_abs(void *dst, void *src, t_dtype dtype)
{
	if (dtype == DT_U8)
		*(uint8_t *)dst = *(uint8_t *)src;
	else if (dtype == DT_I32)
		*(int32_t *)dst = abs(*(int32_t *)src);
	else if (dtype == DT_I64)
		*(int64_t *)dst = llabs(*(int64_t *)src);
	else if (dtype == DT_F32)
		*(float *)dst = fabsf(*(float *)src);
	else if (dtype == DT_F64)
		*(double *)dst = fabs(*(double *)src);
	else if (dtype == DT_C64)
		*(float *)dst = cabsf(*(float complex *)src);
	else if (dtype == DT_C128)
		*(double *)dst = cabs(*(double complex *)src);
}

t_tensr	*tensr_abs(const t_tensr *t, t_tensr *out)
{
	t_iter	it;
	void	*src;
	void	*dst;

	if (!t)
		return (NULL);
	out = initialize(t, out, &it);
	if (!out)
		return (NULL);
	while (iter_next(&it))
	{
		src = tensr_get(t, it.indices);
		dst = tensr_get(out, it.indices);
		assign_abs(dst, src, t->dtype);
	}
	return (out);
}
