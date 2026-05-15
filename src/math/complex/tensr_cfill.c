/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:11:55 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/14 01:22:21 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr_math.h>

t_bool	tensr_cfill(t_tensr *t, double complex value)
{
	t_iter	it;
	void	*dst;

	if (!t || !iter_init(&t->layout, &it) || (t->dtype != DT_C64
			&& t->dtype != DT_C128))
		return (FALSE);
	while (iter_next(&it))
	{
		dst = tensr_get(t, it.indices);
		if (t->dtype == DT_C64)
			*(float complex *)dst = (float complex)value;
		else if (t->dtype == DT_C128)
			*(double complex *)dst = value;
	}
	return (TRUE);
}
