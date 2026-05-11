/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_dot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:40:00 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 22:23:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_math.h>

static t_bool	is_complex(t_dtype dtype)
{
	return (dtype == DT_C64 || dtype == DT_C128);
}

t_tensr	*tensr_dot(const t_tensr *a, const t_tensr *b)
{
	int	ndim_a;
	int	ndim_b;

	if (!a || !b)
		return (NULL);
	if (is_complex(a->dtype) && is_complex(b->dtype))
		return (tensr_cdot(a, b));
	ndim_a = a->layout.ndim;
	ndim_b = b->layout.ndim;
	if (ndim_a == 0 && ndim_b == 0)
		return (tensr_mul(a, b, NULL));
	if (ndim_a == 1 && ndim_b == 1)
		return (tensr_inner(a, b, 1, (size_t[]){0}));
	if (ndim_a == 2 && ndim_b == 2)
		return (tensr_matmul(a, b, NULL));
	return (NULL);
}
