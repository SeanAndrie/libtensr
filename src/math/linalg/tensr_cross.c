/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cross.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 03:44:49 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 20:48:05 by sgadinga         ###   ########.fr       */
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
 * a[1]*b[2] - a[2]*b[1]
 * a[2]*b[0] - a[0]*b[2]
 * a[0]*b[1] - a[1]*b[0]
 */
static void	*cross_entry(const t_tensr *a, const t_tensr *b,
		const size_t a_index, const size_t b_index)
{
	void			*raw;
	static t_result	a_res;
	void			*entry;

	raw = mul_func(tensr_get(a, (size_t[]){a_index}), tensr_get(b,
				(size_t[]){b_index}), a->dtype);
	ft_memcpy(&a_res, raw, a->elemsize);
	entry = sub_func(&a_res, mul_func(tensr_get(a, (size_t[]){b_index}),
				tensr_get(b, (size_t[]){a_index}), a->dtype), a->dtype);
	return (entry);
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
	if (!tensr_set(out, cross_entry(a, b, 1, 2), (size_t[]){0}))
		return (tensr_free(out), NULL);
	if (!tensr_set(out, cross_entry(a, b, 2, 0), (size_t[]){1}))
		return (tensr_free(out), NULL);
	if (!tensr_set(out, cross_entry(a, b, 0, 1), (size_t[]){2}))
		return (tensr_free(out), NULL);
	return (out);
}
