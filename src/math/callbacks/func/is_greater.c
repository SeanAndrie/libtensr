/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_greater.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 02:47:44 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 02:51:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <utils/tensr_callbacks.h>

t_bool	is_greater(const void *a, const void *b, t_dtype dtype)
{
	if (dtype == DT_U8)
		return (*(uint8_t *)a > *(uint8_t *)b);
	else if (dtype == DT_I32)
		return (*(int32_t *)a > *(int32_t *)b);
	else if (dtype == DT_I64)
		return (*(int64_t *)a > *(int64_t *)b);
	else if (dtype == DT_F32)
		return (*(float *)a > *(float *)b);
	else if (dtype == DT_F64)
		return (*(double *)a > *(double *)b);
	return (false);
}
