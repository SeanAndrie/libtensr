/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:57:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/02 16:18:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

bool    iter_init(t_layout *l, t_iter *it)
{
	int	i;

	if (!l)
	{
		ft_dprintf(STDERR_FILENO,
			"libtensr: iter_init: tensor layout is missing\n");
        return (false);
	}
    else if (!it)
    {
		ft_dprintf(STDERR_FILENO,
			"libtensr: iter_init: iterator is missing\n");
        return (false);
    }
	it->total = 1;
	i = 0;
	while (i < l->ndim)
		it->total *= l->shape[i++];
	it->layout = l;
	it->counter = 0;
    ft_memset(it->indices, 0, sizeof(it->indices));
    return (true);
}
