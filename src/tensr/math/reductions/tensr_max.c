/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:19:43 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/07 02:30:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/callbacks.h>

t_tensr	*tensr_max(const t_tensr *t, const int n_axes, const size_t *axes)
{
	t_reduce_op	reduce_op;

	if (!t || !axes || n_axes <= 0)
		return (NULL);
	reduce_op = (t_reduce_op){max_init, max_apply, NULL};
	return (tensr_reduce(t, n_axes, axes, reduce_op));
}
