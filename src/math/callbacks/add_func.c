/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:25:00 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 20:32:33 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <utils/tensr_callbacks.h>

void	add_func(void *a, void *b, void *out, t_dtype dtype)
{
	if (dtype == DT_I32)
		*(int *)out = *(int *)a + *(int *)b;
	else if (dtype == DT_I64)
		*(long long *)out = *(long long *)a + *(long long *)b;
	else if (dtype == DT_F32)
		*(float *)out = *(float *)a + *(float *)b;
	else if (dtype == DT_F64)
		*(double *)out = *(double *)a + *(double *)b;
}
