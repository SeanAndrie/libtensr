/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:19:43 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/02 15:56:05 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

static void	typed_max(void *a, const void *b, t_dtype dtype)
{
	if (dtype == DT_I32)
	{
		if (*(const int *)b > *(int *)a)
			*(int *)a = *(const int *)b;
	}
	else if (dtype == DT_I64)
	{
		if (*(const long long *)b > *(long long *)a)
			*(long long *)a = *(const long long *)b;
	}
	else if (dtype == DT_F32)
	{
		if (*(const float *)b > *(float *)a)
			*(float *)a = *(const float *)b;
	}
	else if (dtype == DT_F64)
	{
		if (*(const double *)b > *(double *)a)
			*(double *)a = *(const double *)b;
	}
}

static void	max_init(void *acc, t_dtype dtype)
{
	if (dtype == DT_I32)
		*(int *)acc = INT_MIN;
	else if (dtype == DT_I64)
		*(long long *)acc = LLONG_MIN;
	else if (dtype == DT_F32)
		*(float *)acc = -FLT_MAX;
	else if (dtype == DT_F64)
		*(double *)acc = -DBL_MAX;
}

static void	max_apply(void *acc, const void *value, t_dtype dtype)
{
	typed_max(acc, value, dtype);
}

static void	max_finalize(void *acc, size_t n, t_dtype dtype)
{
	(void)acc;
	(void)n;
	(void)dtype;
}

t_tensr	*tensr_max(const t_tensr *t, const int n_axes, const size_t *axes)
{
	t_reduce_op	reduce_op;

	if (!t || !axes || n_axes <= 0)
		return (NULL);
	reduce_op = (t_reduce_op){max_init, max_apply, max_finalize};
	return (tensr_reduce(t, n_axes, axes, reduce_op));
}
