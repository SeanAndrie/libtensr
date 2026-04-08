/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:35:39 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/07 02:31:05 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/core.h>
#include <tensr/core_math.h>
#include <utils/tensr_callbacks.h>

t_tensr	*tensr_sum(const t_tensr *t, const int n_axes, const size_t *axes)
{
	t_reduce_op	reduce_op;

	if (!t || !axes || n_axes <= 0)
		return (NULL);
	reduce_op = (t_reduce_op){sum_init, sum_apply, NULL};
	return (tensr_reduce(t, n_axes, axes, reduce_op));
}
