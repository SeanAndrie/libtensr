/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_is_contiguous.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:27:00 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/01 23:35:57 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_bool	tensr_is_contiguous(const t_tensr *t)
{
	int			i;
	t_layout	l;
	size_t		expected_stride;

	if (!t)
		return (false);
	l = t->layout;
	i = l.ndim - 1;
	expected_stride = 1;
	while (i >= 0)
	{
		if (l.stride[i] != expected_stride)
			return (false);
		expected_stride *= l.shape[i];
		i--;
	}
	return (true);
}
