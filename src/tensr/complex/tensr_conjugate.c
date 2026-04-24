/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_conjugate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:49:54 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 22:01:14 by sgadinga         ###   ########.fr       */
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

t_tensr	*tensr_conjugate(const t_tensr *t, t_tensr *out)
{
	t_iter	it;
	void	*dst;
	void	*src;

	if (!t || (t->dtype != DT_C64 && t->dtype != DT_C128))
		return (NULL);
	out = initialize(t, out, &it);
	if (!out)
		return (NULL);
	while (iter_next(&it))
	{
		src = tensr_get(t, it.indices);
		dst = tensr_get(out, it.indices);
		if (t->dtype == DT_C64)
			*(float complex *)dst = conjf(*(float complex *)src);
		else if (t->dtype == DT_C128)
			*(double complex *)dst = conj(*(double complex *)src);
	}
	return (out);
}
