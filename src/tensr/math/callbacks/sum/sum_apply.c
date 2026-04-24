/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:57:53 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 23:02:32 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_callbacks.h>

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
	else if (dtype == DT_C64)
		*(float complex *)acc += *(const float complex *)value;
	else if (dtype == DT_C128)
		*(double complex *)acc += *(const double complex *)value;
}
