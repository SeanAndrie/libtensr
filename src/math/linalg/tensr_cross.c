/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 03:44:49 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 04:31:14 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>

static void	*mul_func(void *a, void *b, t_dtype dtype)
{
	static t_result	res;

	if (dtype == DT_I32)
	{
		res.i = *(int *)a * *(int *)b;
		return (&res.i);
	}
	else if (dtype == DT_I64)
	{
		res.l = *(long long *)a * *(long long *)b;
		return (&res.l);
	}
	else if (dtype == DT_F32)
	{
		res.f = *(float *)a * *(float *)b;
		return (&res.f);
	}
	else if (dtype == DT_F64)
	{
		res.d = *(double *)a * *(double *)b;
		return (&res.d);
	}
	return (NULL);
}

static void	*sub_func(void *a, void *b, t_dtype dtype)
{
	static t_result	res;

	if (dtype == DT_I32)
	{
		res.i = *(int *)a - *(int *)b;
		return (&res.i);
	}
	else if (dtype == DT_I64)
	{
		res.l = *(long long *)a - *(long long *)b;
		return (&res.l);
	}
	else if (dtype == DT_F32)
	{
		res.f = *(float *)a - *(float *)b;
		return (&res.f);
	}
	else if (dtype == DT_F64)
	{
		res.d = *(double *)a - *(double *)b;
		return (&res.d);
	}
	return (NULL);
}

/*
 * a[0, 1]*b[0, 2] - a[0, 2]*b[0, 1]
 * a[0, 2]*b[0, 0] - a[0, 0]*b[0, 2]
 * a[0, 0]*b[0, 1] - a[0, 1]*b[0, 0]
 */
static void	*cross_entry(const t_tensr *a, const t_tensr *b,
		const size_t *a_index, const size_t *b_index)
{
	static t_result	a_val;
	void			*raw;

	raw = mul_func(tensr_get(a, a_indices), tensr_get(b, b_indices), a->dtype);
	ft_memcpy(&a_val, raw, a->elemsize);
	return (sub_func(&a_val, mul_func(tensr_get(a, b_indices), tensr_get(b,
					a_indices), a->dtype), a->dtype));
}

t_tensr	*tensr_cross(const t_tensr *a, const t_tensr *b)
{
	t_tensr	*out;

	if (!a || !b)
		return (NULL);
	if (a->layout.ndim != 1 || b->layout.ndim != 1)
		return (NULL);
	if (a->layout.shape[0] != 3 || b->layout.shape[0] != 3)
		return (NULL);
	out = tensr_alloc(1, (size_t[]){3}, a->dtype);
	if (!out)
		return (NULL);
	if (!tensr_set(out, cross_entry(a, b, (size_t[]){1}, (size_t[]){2}),
			(size_t[]){0}))
		return (tensr_free(out), NULL);
	if (!tensr_set(out, cross_entry(a, b, (size_t[]){2}, (size_t[]){0}),
			(size_t[]){1}))
		return (tensr_free(out), NULL);
	if (!tensr_set(out, cross_entry(a, b, (size_t[]){0}, (size_t[]){1}),
			(size_t[]){2}))
		return (tensr_free(out), NULL);
	return (out);
}
