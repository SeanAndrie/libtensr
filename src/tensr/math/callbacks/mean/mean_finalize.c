/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mean_finalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:57:39 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 23:08:50 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_callbacks.h>

void	mean_finalize(void *acc, size_t count, t_dtype dtype)
{
	if (dtype == DT_U8)
		*(uint8_t *)acc /= (uint8_t)count;
	else if (dtype == DT_I32)
		*(int32_t *)acc /= (int32_t)count;
	else if (dtype == DT_I64)
		*(int64_t *)acc /= (int64_t)count;
	else if (dtype == DT_F32)
		*(float *)acc /= (float)count;
	else if (dtype == DT_F64)
		*(double *)acc /= (double)count;
}
