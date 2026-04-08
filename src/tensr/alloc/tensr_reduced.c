/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reduced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:28:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 20:48:48 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr	*tensr_reduced(const t_layout *l, const int n_axes, const size_t *axes,
		t_dtype dtype)
{
	int			i;
	int			j;
	t_tensr		*out;
	t_layout	layout;
	int			out_dim;

	if (!l || !axes || n_axes <= 0)
		return (NULL);
	if (!layout_alloc(l->ndim - n_axes, &layout))
		return (tensr_alloc(0, NULL, dtype));
	i = -1;
	j = 0;
	out_dim = 0;
	while (++i < l->ndim)
	{
		if (j < n_axes && (int)axes[j] == i)
			j++;
		else
			layout.shape[out_dim++] = l->shape[i];
	}
	out = tensr_alloc(layout.ndim, layout.shape, dtype);
	layout_free(&layout);
	return (out);
}
