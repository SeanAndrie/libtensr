/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_sqrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:57:22 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 19:47:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <tensr/tensr.h>

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

t_tensr	*tensr_sqrt(const t_tensr *t, t_tensr *out)
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
		if (out->dtype == DT_F32)
			*(float *)dst = sqrtf(*(float *)src);
		else if (out->dtype == DT_F64)
			*(double *)dst = sqrt(*(double *)src);
	}
	return (out);
}
