/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_dot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:40:00 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/04 21:57:47 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>

t_tensr	*tensr_dot(const t_tensr *a, const t_tensr *b)
{
	t_tensr	*out;
	t_tensr	*temp;

	if (!a || !b || a->dtype != b->dtype)
		return (NULL);
	temp = tensr_mul(a, b);
	if (!temp)
		return (NULL);
	out = tensr_sum(temp, 1, (size_t[]){0});
	tensr_free(temp);
	return (out);
}
