/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cdot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 22:08:34 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 22:58:23 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_debug.h>
#include <tensr/tensr_math.h>

static t_bool	is_complex(t_dtype dtype)
{
	return (dtype == DT_C64 || dtype == DT_C128);
}

t_tensr	*tensr_cdot(const t_tensr *a, const t_tensr *b)
{
	t_tensr	*out;
	t_tensr	*conj_a;

	if (!a || !b || !is_complex(a->dtype) || !is_complex(b->dtype))
		return (NULL);
	if (a->dtype != b->dtype)
		return (NULL);
	conj_a = tensr_conjugate(a, NULL);
	if (!conj_a)
		return (NULL);
	out = tensr_inner(conj_a, b, 1, (size_t[]){0});
	tensr_free(conj_a);
	if (!out)
		return (NULL);
	return (out);
}
