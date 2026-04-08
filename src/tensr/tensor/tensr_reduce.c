/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:32:56 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/18 01:47:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/core.h>

t_tensr	*tensr_reduce(const t_tensr *t, const int n_axes, const size_t *axes,
		t_reduce_op op)
{
	if (!t || !axes || n_axes <= 0)
		return (NULL);
	return (tensr_reduce_strided(t, n_axes, axes, op));
}
