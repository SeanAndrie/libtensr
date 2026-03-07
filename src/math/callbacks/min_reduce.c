/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 02:29:36 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/07 02:31:22 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <utils/tensr_callbacks.h>

void	typed_min(void *a, const void *b, t_dtype dtype)
{
	if (dtype == DT_I32)
	{
		if (*(const int *)b < *(int *)a)
			*(int *)a = *(const int *)b;
	}
	else if (dtype == DT_I64)
	{
		if (*(const long long *)b < *(long long *)a)
			*(long long *)a = *(const long long *)b;
	}
	else if (dtype == DT_F32)
	{
		if (*(const float *)b < *(float *)a)
			*(float *)a = *(const float *)b;
	}
	else if (dtype == DT_F64)
	{
		if (*(const double *)b < *(double *)a)
			*(double *)a = *(const double *)b;
	}
}

void	min_init(void *acc, t_dtype dtype)
{
	if (dtype == DT_I32)
		*(int *)acc = INT_MAX;
	else if (dtype == DT_I64)
		*(long long *)acc = LLONG_MAX;
	else if (dtype == DT_F32)
		*(float *)acc = FLT_MAX;
	else if (dtype == DT_F64)
		*(double *)acc = DBL_MAX;
}

void	min_apply(void *acc, const void *value, t_dtype dtype)
{
	typed_min(acc, value, dtype);
}
