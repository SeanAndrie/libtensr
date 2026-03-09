/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mean_reduce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:10:22 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/07 16:16:21 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <utils/tensr_callbacks.h>

void    mean_finalize(void *acc, size_t count, t_dtype dtype)
{
    if (dtype == DT_I32)
        *(int *)acc /= (int)count;
    else if (dtype == DT_I64)
        *(long long *)acc /= (long long)count;
    else if (dtype == DT_F32)
        *(float *)acc /= (float)count;
    else if (dtype == DT_F64)
        *(double *)acc /= (double)count;
}
