/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_inner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:27:12 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 11:05:24 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core_math.h>

t_tensr	*tensr_inner(const t_tensr *a, const t_tensr *b, const size_t n_axes,
		const size_t *axes)
{
	t_tensr	*out;
	t_tensr	*temp;

	if (!a || !b || !layout_equal(&a->layout, &b->layout))
		return (NULL);
	temp = tensr_mul(a, b, NULL);
	if (!temp)
		return (NULL);
	out = tensr_sum(temp, n_axes, axes);
	tensr_free(temp);
	return (out);
}
