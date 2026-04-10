/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reduced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:28:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 20:58:42 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <tensr/tensr.h>

t_tensr	*tensr_reduced(const t_tensr *t, const int n_axes, t_bool *reduce_mask)
{
	int		i;
	int		j;
	int		ndim;
	size_t	shape[MAX_NDIM];

	if (n_axes <= 0 || !t || !reduce_mask)
		return (NULL);
	ndim = t->layout.ndim - n_axes;
	j = 0;
	i = -1;
	while (++i < t->layout.ndim)
	{
		if (reduce_mask[i])
			continue ;
		shape[j++] = t->layout.shape[i];
	}
	if (j == 0)
		return (tensr_alloc(0, NULL, t->dtype));
	return (tensr_alloc(ndim, shape, t->dtype));
}
