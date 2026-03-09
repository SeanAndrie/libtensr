/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:01:42 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/07 02:31:15 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>
#include <utils/tensr_callbacks.h>

t_tensr	*tensr_min(const t_tensr *t, const int n_axes, const size_t *axes)
{
	t_reduce_op	reduce_op;

	if (!t || !axes || n_axes <= 0)
		return (NULL);
	reduce_op = (t_reduce_op){min_init, min_apply, NULL};
	return (tensr_reduce(t, n_axes, axes, reduce_op));
}
