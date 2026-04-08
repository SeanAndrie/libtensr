/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:37:22 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 20:47:14 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/core.h>
#include <utils/tensr_callbacks.h>

void	div_func(void *a, void *b, void *out, t_dtype dtype)
{
	if (dtype == DT_U8)
		*(uint8_t *)out = *(uint8_t *)a / *(uint8_t *)b;
	else if (dtype == DT_I32)
		*(int32_t *)out = *(int32_t *)a / *(int32_t *)b;
	else if (dtype == DT_I64)
		*(int64_t *)out = *(int64_t *)a / *(int64_t *)b;
	else if (dtype == DT_F32)
		*(float *)out = *(float *)a / *(float *)b;
	else if (dtype == DT_F64)
		*(double *)out = *(double *)a / *(double *)b;
}
