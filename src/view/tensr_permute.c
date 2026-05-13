/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_permute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:55:41 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 01:14:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr	*tensr_permute(const t_tensr *t, const size_t *perm)
{
	int			i;
	t_tensr		*v;
	t_layout	layout;

	if (!t || !perm)
		return (NULL);
	if (!layout_alloc(t->layout.ndim, &layout))
		return (NULL);
	i = -1;
	while (++i < t->layout.ndim)
	{
		layout.shape[i] = t->layout.shape[perm[i]];
		layout.stride[i] = t->layout.stride[perm[i]];
	}
	v = tensr_view(t, t->data, &layout);
	layout_free(&layout);
	return (v);
}
