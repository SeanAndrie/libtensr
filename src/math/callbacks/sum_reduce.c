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
	if (dtype == DT_I32)
		*(int *)acc = 0;
	else if (dtype == DT_I64)
		*(long long *)acc = 0;
	else if (dtype == DT_F32)
		*(float *)acc = 0.0f;
	else if (dtype == DT_F64)
		*(double *)acc = 0.0;
}

void	sum_apply(void *acc, const void *value, t_dtype dtype)
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
