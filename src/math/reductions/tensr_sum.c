/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:35:39 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/04 21:33:28 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>

static void	sum_init(void *acc, t_dtype dtype)
{
	if (dtype == DT_I32)
		*(int *)acc = 0;
	else if (dtype == DT_I64)
		*(long long *)acc = 0;
	else if (dtype == DT_F32)
		*(float *)acc = 0.0f;
	else if (dtype == DT_F64)
		*(double *)acc = 0.0;
}

static void	sum_apply(void *acc, const void *value, t_dtype dtype)
{
	if (dtype == DT_I32)
		*(int *)acc += *(const int *)value;
	else if (dtype == DT_I64)
		*(long long *)acc += *(const long long *)value;
	else if (dtype == DT_F32)
		*(float *)acc += *(const float *)value;
	else if (dtype == DT_F64)
		*(double *)acc += *(const double *)value;
}

static void	sum_finalize(void *acc, size_t n, t_dtype dtype)
{
	(void)acc;
	(void)n;
	(void)dtype;
}

t_tensr	*tensr_sum(const t_tensr *t, const int n_axes, const size_t *axes)
{
	t_reduce_op	reduce_op;

	if (!t || !axes || n_axes <= 0)
		return (NULL);
	reduce_op = (t_reduce_op){sum_init, sum_apply, sum_finalize};
	return (tensr_reduce(t, n_axes, axes, reduce_op));
}
