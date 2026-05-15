/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_creal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 23:19:51 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/14 01:23:05 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr_math.h>

static t_dtype	convert_dtype(t_dtype dtype)
{
	if (dtype == DT_C64)
		return (DT_F32);
	if (dtype == DT_C128)
		return (DT_F64);
	return (0);
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
		ret = tensr_alloc(t->layout.ndim, t->layout.shape,
				convert_dtype(t->dtype));
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

t_tensr	*tensr_creal(const t_tensr *t, t_tensr *out)
{
	t_iter	it;
	void	*dst;
	void	*src;

	if (!t)
		return (NULL);
	if (t->dtype != DT_C64 && t->dtype != DT_C128)
		return (tensr_copy(t));
	out = initialize(t, out, &it);
	if (!out)
		return (NULL);
	while (iter_next(&it))
	{
		src = tensr_get(t, it.indices);
		dst = tensr_get(out, it.indices);
		if (t->dtype == DT_C64)
			*(float *)dst = crealf(*(float complex *)src);
		else if (t->dtype == DT_C128)
			*(double *)dst = creal(*(double complex *)src);
	}
	return (out);
}
