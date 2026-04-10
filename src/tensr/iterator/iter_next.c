/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:23:44 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 21:23:45 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_bool	iter_next(t_iter *it)
{
	int	i;

	if (it->counter >= it->total)
		return (false);
	if (it->counter == 0)
	{
		it->counter++;
		return (true);
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
	return (true);
}
