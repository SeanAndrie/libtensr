/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:24:45 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 21:24:47 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_bool	layout_alloc(const int ndim, t_layout *l)
{
	if (!l)
		return (false);
	ft_memset(l, 0, sizeof(t_layout));
	l->ndim = ndim;
	l->shape = l->shape_buf;
	l->stride = l->stride_buf;
	return (true);
}
