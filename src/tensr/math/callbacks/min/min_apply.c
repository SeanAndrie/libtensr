/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:45:40 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 23:57:20 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_callbacks.h>

void	min_apply(void *a, const void *b, t_dtype dtype)
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
