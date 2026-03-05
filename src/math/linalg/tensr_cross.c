/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 03:44:49 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/06 01:44:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>
#include <utils/tensr_callbacks.h>

static void	set_cross_entry(const t_tensr *a, const t_tensr *b, void *data,
		const size_t *indices)
{
	unsigned char	a_v[MAX_ACC_SIZE];
	unsigned char	b_v[MAX_ACC_SIZE];

	mul_func(tensr_get(a, (size_t[]){indices[0]}), tensr_get(b,
			(size_t[]){indices[1]}), a_v, a->dtype);
	mul_func(tensr_get(a, (size_t[]){indices[1]}), tensr_get(b,
			(size_t[]){indices[0]}), b_v, a->dtype);
	sub_func(a_v, b_v, data, a->dtype);
}

/*
 * a[1]*b[2] - a[2]*b[1] -> [[a]
 * a[2]*b[0] - a[0]*b[2] ->  [b]
 * a[0]*b[1] - a[1]*b[0] ->  [c]]
 */
t_tensr	*tensr_cross(const t_tensr *a, const t_tensr *b)
{
	t_tensr	*out;

	if (!a || !b || a->dtype != b->dtype)
		return (NULL);
	if (a->layout.ndim != 1 || b->layout.ndim != 1)
		return (NULL);
	if (a->layout.shape[0] != 3 || b->layout.shape[0] != 3)
		return (NULL);
	out = tensr_alloc(1, (size_t[]){3}, a->dtype);
	if (!out)
		return (NULL);
	set_cross_entry(a, b, tensr_get(out, (size_t[]){0}), (size_t[]){1, 2});
	set_cross_entry(a, b, tensr_get(out, (size_t[]){1}), (size_t[]){2, 0});
	set_cross_entry(a, b, tensr_get(out, (size_t[]){2}), (size_t[]){0, 1});
	return (out);
}
