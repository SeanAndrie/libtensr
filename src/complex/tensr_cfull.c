/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cfull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:12:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 21:12:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr	*tensr_cfull(double complex value, const int ndim, const size_t *shape,
		t_dtype dtype)
{
	t_iter	it;
	t_tensr	*t;
	void	*dst;

	if (!shape || ndim < 0 || (dtype != DT_C64 && dtype != DT_C128))
		return (NULL);
	t = tensr_alloc(ndim, shape, dtype);
	if (!t)
		return (NULL);
	if (!iter_init(&t->layout, &it))
		return (tensr_free(t), NULL);
	while (iter_next(&it))
	{
		dst = tensr_get(t, it.indices);
		if (dtype == DT_C64)
			*(float complex *)dst = (float complex)value;
		else if (dtype == DT_C128)
			*(double complex *)dst = value;
	}
	return (t);
}
