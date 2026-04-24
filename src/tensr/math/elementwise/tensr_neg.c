/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:52:01 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 20:22:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

static t_tensr	*initialize(const t_tensr *t, t_tensr *out, t_iter *it)
{
	t_tensr	*ret;
	t_bool	alloc;

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

static void	negate(void *dst, void *src, t_dtype dtype)
{
	if (dtype == DT_U8)
		*(uint8_t *)dst = *(uint8_t *)src;
	else if (dtype == DT_I32)
		*(int32_t *)dst = -(*(int32_t *)src);
	else if (dtype == DT_I64)
		*(int64_t *)dst = -(*(int64_t *)src);
	else if (dtype == DT_F32)
		*(float *)dst = -(*(float *)src);
	else if (dtype == DT_F64)
		*(double *)dst = -(*(double *)src);
	else if (dtype == DT_C64)
		*(float complex *)dst = -(*(float complex *)src);
	else if (dtype == DT_C128)
		*(double complex *)dst = -(*(double complex *)src);
}

t_tensr	*tensr_neg(const t_tensr *t, t_tensr *out)
{
	t_iter	it;
	void	*src;
	void	*dst;

	out = initialize(t, out, &it);
	if (!out)
		return (NULL);
	while (iter_next(&it))
	{
		src = tensr_get(t, it.indices);
		dst = tensr_get(out, it.indices);
		negate(dst, src, out->dtype);
	}
	return (out);
}
