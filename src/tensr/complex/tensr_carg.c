/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_carg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 23:51:33 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 23:55:08 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

static t_dtype	convert_dtype(t_dtype dtype)
{
	if (dtype == DT_C64)
		return (DT_F32);
	if (dtype == DT_C128)
		return (DT_F64);
	return (0);
}

t_tensr	*tensr_carg(const t_tensr *t)
{
	t_iter	it;
	t_tensr	*out;
	void	*dst;
	void	*src;

	if (!t || (t->dtype != DT_C64 && t->dtype != DT_C128))
		return (NULL);
	out = tensr_alloc(t->layout.ndim, t->layout.shape, convert_dtype(t->dtype));
	if (!out || !iter_init(&out->layout, &it))
		return (tensr_free(out), NULL);
	while (iter_next(&it))
	{
		src = tensr_get(t, it.indices);
		dst = tensr_get(out, it.indices);
		if (t->dtype == DT_C64)
			*(float *)dst = cargf(*(float complex *)src);
		if (t->dtype == DT_C128)
			*(double *)dst = cargf(*(double complex *)src);
	}
	return (out);
}
