/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_reduced.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:13:35 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 02:50:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_layout	layout_reduced(const t_layout *l, const t_bool *is_reduced)
{
	int			i;
	int			j;
	t_layout	reduced_l;

	j = 0;
	i = -1;
	ft_memset(&reduced_l, 0, sizeof(t_layout));
	if (!l || !is_reduced)
		return (reduced_l);
	reduced_l.shape = reduced_l.shape_buf;
	reduced_l.stride = reduced_l.stride_buf;
	while (++i < l->ndim)
	{
		if (!is_reduced[i])
			continue ;
		reduced_l.shape[j] = l->shape[i];
		reduced_l.stride[j] = l->stride[i];
		j++;
	}
	reduced_l.ndim = j;
	return (reduced_l);
}
