/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_argmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 01:35:09 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 02:51:46 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr_math.h>
#include <utils/tensr_callbacks.h>

t_tensr	*tensr_argmax(const t_tensr *t, const int n_axes, const size_t *axes)
{
	if (!t || !axes || n_axes <= 0 || t->dtype == DT_C64 || t->dtype == DT_C128)
		return (NULL);
	return (tensr_arg(t, n_axes, axes, is_greater));
}
