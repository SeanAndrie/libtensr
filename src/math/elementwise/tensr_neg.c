/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:52:01 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/06 00:37:12 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>

static bool cast_negative_scalar(t_array *arr, t_dtype dtype)
{
    unsigned char n[MAX_ACC_SIZE];
    
    if (dtype == DT_I32)
    {
        *(int *)n = -1;
        *arr = arr_i32((int *)n, 1);
    }
    else if (dtype == DT_I64)
    {
        *(long long *)n = -1;
        *arr = arr_i64((long long *)n, 1);
    }
    else if (dtype == DT_F32)
    {
        *(float *)n = -1.0f;
        *arr = arr_f32((float *)n, 1);
    }
    else if (dtype == DT_F64)
    {
        *(double *)n = -1.0;
        *arr = arr_f64((double *)n, 1);
    }
    else
        return (false);
    return (true);
}

t_tensr *tensr_neg(const t_tensr *t)
{
    t_tensr *out;
    t_array sca_n;
    t_tensr *sca_t;

    if (!t)
        return (NULL);
    if (!cast_negative_scalar(&sca_n, t->dtype))
        return (NULL);
    sca_t = tensr_from_arr(&sca_n, 0, NULL, t->dtype);
    if (!sca_t)
        return (NULL);
    out = tensr_mul(t, sca_t);
    tensr_free(sca_t);
    if (!out)
        return (NULL);
    return (out);
}
