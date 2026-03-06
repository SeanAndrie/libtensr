/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_dot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:40:00 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 00:44:14 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>

t_tensr	*tensr_dot(const t_tensr *a, const t_tensr *b)
{
    int     i;
	t_tensr	*out;
	t_tensr	*temp;
    size_t  axes[MAX_NDIM];

	if (!a || !b || !layout_shape_eq(&a->layout, &b->layout))
		return (NULL);
	temp = tensr_mul(a, b);
	if (!temp)
		return (NULL);
    i = 0;
    while (i < temp->layout.ndim)
    {
        axes[i] = i;
        i++;
    }
	out = tensr_sum(temp, temp->layout.ndim, axes);
	tensr_free(temp);
	return (out);
}
