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

#include <float.h>
#include <tensr/tensr.h>
#include <tensr/callbacks.h>

void	typed_min(void *a, const void *b, t_dtype dtype)
{
	if (dtype == DT_U8)
	{
		if (*(const uint8_t *)b < *(uint8_t *)a)
			*(uint8_t *)a = *(const uint8_t *)b;
	}
	else if (dtype == DT_I32)
	{
		if (*(const int32_t *)b < *(int32_t *)a)
			*(int32_t *)a = *(const int32_t *)b;
	}
	else if (dtype == DT_I64)
	{
		if (*(const int64_t *)b < *(int64_t *)a)
			*(int64_t *)a = *(const int64_t *)b;
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
	if (dtype == DT_U8)
		*(uint8_t *)acc = UINT8_MAX;
	else if (dtype == DT_I32)
		*(int32_t *)acc = INT32_MAX;
	else if (dtype == DT_I64)
		*(int64_t *)acc = INT64_MAX;
	else if (dtype == DT_F32)
		*(float *)acc = FLT_MAX;
	else if (dtype == DT_F64)
		*(double *)acc = DBL_MAX;
}

void	min_apply(void *acc, const void *value, t_dtype dtype)
{
	typed_min(acc, value, dtype);
}
