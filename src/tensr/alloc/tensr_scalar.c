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

#include <core/tensr.h>

t_tensr	*tensr_scalar(double n, t_dtype dtype)
{
	t_tensr	*out;

	out = tensr_alloc(0, NULL, dtype);
	if (!out)
		return (NULL);
	if (dtype == DT_I32)
		*(int *)tensr_get(out, (size_t[]){0}) = (int)n;
	else if (dtype == DT_I64)
		*(long long *)tensr_get(out, (size_t[]){0}) = (long long)n;
	else if (dtype == DT_F32)
		*(float *)tensr_get(out, (size_t[]){0}) = (float)n;
	else if (dtype == DT_F64)
		*(double *)tensr_get(out, (size_t[]){0}) = n;
	return (out);
}
