/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:23:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 21:23:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_bool	iter_init(const t_layout *l, t_iter *it)
{
	int	i;

	if (!l)
	{
		ft_dprintf(STDERR_FILENO, "libtensr: iter_init: layout is missing\n");
		return (FALSE);
	}
	else if (!it)
	{
		ft_dprintf(STDERR_FILENO, "libtensr: iter_init: iterator is missing\n");
		return (FALSE);
	}
	it->total = 1;
	i = 0;
	while (i < l->ndim)
		it->total *= l->shape[i++];
	it->layout = (t_layout *)l;
	it->counter = 0;
	ft_memset(it->indices, 0, sizeof(it->indices));
	return (TRUE);
}
