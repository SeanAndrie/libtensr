/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:47:14 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 23:47:26 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_callbacks.h>

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
