/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_scalar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:18:24 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/10 16:33:08 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr	*tensr_scalar(double n, t_dtype dtype)
{
	t_tensr	*out;

	out = tensr_alloc(0, NULL, dtype);
	if (!out)
		return (NULL);
	if (dtype == DT_U8)
		*(uint8_t *)tensr_get(out, (size_t[]){0}) = (uint8_t)n;
	else if (dtype == DT_I32)
		*(int32_t *)tensr_get(out, (size_t[]){0}) = (int32_t)n;
	else if (dtype == DT_I64)
		*(int64_t *)tensr_get(out, (size_t[]){0}) = (int64_t)n;
	else if (dtype == DT_F32)
		*(float *)tensr_get(out, (size_t[]){0}) = (float)n;
	else if (dtype == DT_F64)
		*(double *)tensr_get(out, (size_t[]){0}) = n;
	return (out);
}
