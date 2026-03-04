/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:18:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/03 16:04:48 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

void	iter_reset(t_iter *it)
{
	if (!it)
		return ;
	it->counter = 0;
	ft_memset(it->indices, 0, sizeof(size_t) * it->layout->ndim);
}
