/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:57:58 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 23:57:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_callbacks.h>

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
