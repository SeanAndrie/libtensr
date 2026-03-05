/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_equal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:18:18 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 22:33:33 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

static bool	is_equal(void *a, void *b, t_dtype dtype)
{
	if (dtype == DT_I32)
		return ((*(int *)a == *(int *)b));
	else if (dtype == DT_I64)
		return ((*(long long *)a == *(long long *)b));
	else if (dtype == DT_F32)
		return ((*(float *)a == *(float *)b));
	else if (dtype == DT_F64)
		return ((*(double *)a == *(double *)b));
	return (false);
}

bool	tensr_equal(const t_tensr *a, const t_tensr *b)
{
	t_iter	it;
	void	*a_v;
	void	*b_v;

	if (!a || !b)
		return (false);
	if (a->dtype != b->dtype || !layout_shape_eq(&a->layout, &b->layout))
		return (false);
	if (!iter_init((t_layout *)&a->layout, &it))
	{
		ft_dprintf(STDERR_FILENO,
			"libtensr: tensr_equal: failed to initialize iterator\n");
		return (false);
	}
	while (iter_next(&it))
	{
		a_v = tensr_get(a, it.indices);
		b_v = tensr_get(b, it.indices);
		if (!a_v || !b_v || !is_equal(a_v, b_v, a->dtype))
			return (false);
	}
	return (true);
}
