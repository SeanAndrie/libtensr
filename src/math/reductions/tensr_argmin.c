/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_argmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:51:17 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 07:55:12 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr_math.h>
#include <utils/tensr_callbacks.h>

t_tensr	*tensr_argmin(const t_tensr *t, const int n_axes, const size_t *axes)
{
	if (!t || !axes || n_axes <= 0 || t->dtype == DT_C64 || t->dtype == DT_C128)
		return (NULL);
	return (tensr_arg(t, n_axes, axes, is_less));
}
