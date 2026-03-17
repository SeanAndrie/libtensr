/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_transpose.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 01:24:21 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/20 14:55:45 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

t_tensr	*tensr_transpose(const t_tensr *t)
{
    t_tensr         *v;
	t_layout        layout;
	size_t			new_shape[2];
	size_t			new_stride[2];

	if (!t || t->layout.ndim != 2)
		return (NULL);
	new_shape[0] = t->layout.shape[1];
	new_shape[1] = t->layout.shape[0];
	new_stride[0] = t->layout.stride[1];
	new_stride[1] = t->layout.stride[0];
    ft_memset(&layout, 0, sizeof(layout));
    layout.ndim = t->layout.ndim;
    layout.shape = new_shape;
    layout.stride = new_stride;
    v = tensr_view(t, t->data, &layout);
    layout_free(&layout);
    return (v);
}
