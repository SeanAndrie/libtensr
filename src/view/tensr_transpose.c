/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_transpose.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 01:24:21 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 23:02:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr	*tensr_transpose(const t_tensr *t)
{
	t_tensr		*v;
	t_layout	layout;
	size_t		shape[2];
	size_t		stride[2];

	if (!t || t->layout.ndim != 2)
		return (NULL);
	shape[0] = t->layout.shape[1];
	shape[1] = t->layout.shape[0];
	stride[0] = t->layout.stride[1];
	stride[1] = t->layout.stride[0];
	layout.ndim = 2;
	layout.shape = shape;
	layout.stride = stride;
	v = tensr_view(t, t->data, &layout);
	return (v);
}
