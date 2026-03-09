/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:40:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/09 16:24:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

static double widen_value(void *value, t_dtype dtype) 
{
    if (dtype == DT_I32)
        return ((double)*(int *)value);
    else if (dtype == DT_I64)
        return ((double)*(long long *)value);
    else if (dtype == DT_F32)
        return ((double)*(float *)value);
    else
        return (*(double *)value);
}

t_tensr *tensr_cast(const t_tensr *t, t_dtype dtype)
{
    t_iter  it;
    double  temp;
    t_tensr *out;
    void    *dst;

    if (t->dtype == dtype)
        return (tensr_copy(t));
    out = tensr_alloc(t->layout.ndim, t->layout.shape, dtype);
    if (!out || !iter_init(&out->layout, &it))
        return (tensr_free(out), NULL);
    while (iter_next(&it))
    {
        dst = tensr_get(out, it.indices);
        temp = widen_value(tensr_get(t, it.indices), t->dtype);
        if (dtype == DT_I32)
            *(int *)dst = (int)temp;
        else if (dtype == DT_I64)
            *(long long *)dst = (long long)temp;
        else if (dtype == DT_F32)
            *(float *)dst = (float)temp;
        else if (dtype == DT_F64)
            *(double *)dst = temp;
    }
    return (out);
}
