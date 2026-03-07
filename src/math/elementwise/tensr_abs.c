/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_abs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:35:54 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/08 03:14:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>
#include <utils/tensr_callbacks.h>

t_tensr	*tensr_abs(const t_tensr *t)
{
	t_iter			it;
	t_tensr			*out;
    void            *src;
    void            *dst;

	if (!t)
		return (NULL);
	out = tensr_alloc(t->layout.ndim, t->layout.shape, t->dtype);
	if (!out || !iter_init(&out->layout, &it))
		return (NULL);
	while (iter_next(&it))
	{
        src = tensr_get(t, it.indices);
        dst = tensr_get(out, it.indices);
        abs_func(src, dst, t->dtype);
	}
	return (out);
}
