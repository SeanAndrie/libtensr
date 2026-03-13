/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_reduce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 02:23:27 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/07 02:28:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <utils/tensr_callbacks.h>

void	sum_init(void *acc, t_dtype dtype)
{
	if (dtype == DT_U8)
		*(uint8_t *)acc = 0;
	else if (dtype == DT_I32)
		*(int32_t *)acc = 0;
	else if (dtype == DT_I64)
		*(int64_t *)acc = 0;
	else if (dtype == DT_F32)
		*(float *)acc = 0.0f;
	else if (dtype == DT_F64)
		*(double *)acc = 0.0;
}

void	sum_apply(void *acc, const void *value, t_dtype dtype)
{
	if (dtype == DT_U8)
		*(uint8_t *)acc += *(const uint8_t *)value;
	else if (dtype == DT_I32)
		*(int32_t *)acc += *(const int32_t *)value;
	else if (dtype == DT_I64)
		*(int64_t *)acc += *(const int64_t *)value;
	else if (dtype == DT_F32)
		*(float *)acc += *(const float *)value;
	else if (dtype == DT_F64)
		*(double *)acc += *(const double *)value;
}
