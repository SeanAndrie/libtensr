/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 03:06:48 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/08 03:18:09 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <core/tensr.h>
#include <utils/tensr_callbacks.h>

void    abs_func(void *value, void *out, t_dtype dtype)
{
    if (dtype == DT_I32)
        *(int *)out = abs(*(int *)value);
    else if (dtype == DT_I64)
        *(long long *)out = llabs(*(long long *)value);
    else if (dtype == DT_F32)
        *(float *)out = fabsf(*(float *)value);
    else if (dtype == DT_F64)
        *(double *)out = fabs(*(double *)value);
}
