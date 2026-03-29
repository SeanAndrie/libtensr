/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_equal_eps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 02:01:02 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 01:14:08 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>
#include <math.h>

static bool	is_equal(void *a, void *b, double epsilon, t_dtype dtype)
{
	if (dtype == DT_F32)
		return (fabsf(*(float *)a - *(float *)b) < (float)epsilon);
	else if (dtype == DT_F64)
		return (fabs(*(double *)a - *(double *)b) < epsilon);
	return (false);
}

bool	tensr_equal_eps(const t_tensr *a, const t_tensr *b, double epsilon)
{
	t_iter	it;
	void	*a_v;
	void	*b_v;

	if (!a || !b)
		return (false);
	if (a->dtype == DT_I32 || a->dtype == DT_I64)
		return (false);
	if (a->dtype != b->dtype || !layout_equal(&a->layout, &b->layout))
		return (false);
	if (!iter_init((t_layout *)&a->layout, &it))
	{
		ft_dprintf(STDERR_FILENO,
			"libtensr: tensr_equal_eps: failed to initialize iterator.\n");
		return (false);
	}
	while (iter_next(&it))
	{
		a_v = tensr_get(a, it.indices);
		b_v = tensr_get(b, it.indices);
		if (!a_v || !b_v || !is_equal(a_v, b_v, epsilon, a->dtype))
			return (false);
	}
	return (true);
}
