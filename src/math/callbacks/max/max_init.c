/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:58:08 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 23:58:09 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <utils/tensr_callbacks.h>

void	max_init(void *acc, t_dtype dtype)
{
	if (dtype == DT_U8)
		*(uint8_t *)acc = 0;
	else if (dtype == DT_I32)
		*(int32_t *)acc = INT32_MIN;
	else if (dtype == DT_I64)
		*(int64_t *)acc = INT64_MIN;
	else if (dtype == DT_F32)
		*(float *)acc = -FLT_MAX;
	else if (dtype == DT_F64)
		*(double *)acc = -DBL_MAX;
}
