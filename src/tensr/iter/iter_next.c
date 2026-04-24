/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:23:44 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 00:44:56 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_bool	iter_next(t_iter *it)
{
	int	i;

	if (it->counter >= it->total)
		return (FALSE);
	if (it->counter == 0)
	{
		it->counter++;
		return (TRUE);
	}
	i = it->layout->ndim - 1;
	while (i >= 0)
	{
		it->indices[i]++;
		if (it->indices[i] < it->layout->shape[i])
			break ;
		it->indices[i] = 0;
		i--;
	}
	it->counter++;
	return (TRUE);
}
