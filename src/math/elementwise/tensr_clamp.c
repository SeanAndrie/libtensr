/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_clamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 19:12:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/08 19:25:39 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <core/tensr.h>
#include <core/tensr_math.h>

t_tensr *tensr_clamp(const t_tensr *t, double min, double max)
{
    t_iter  it;
    t_tensr *out;
    void    *src;
    void    *dst;

    out = tensr_alloc(t->layout.ndim, t->layout.shape, t->dtype);
    if (!out)
        return (NULL);
    if (!iter_init(&out->layout, &it))
        return (tensr_free(out), NULL);
    while (iter_next(&it))
    {
        src = tensr_get(t, it.indices);
        dst = tensr_get(out, it.indices);
        if (t->dtype == DT_I32)
            *(int *)dst = fmax(min, fmin(*(int *)src, max));
        else if (t->dtype == DT_I64)
            *(long long *)dst = fmax(min, fmin(*(long long *)src, max));
        else if (t->dtype == DT_F32)
            *(float *)dst = fmaxf(min, fmin(*(float *)src, max));
        else if (t->dtype == DT_F64)
            *(double *)dst = fmax(min, fmin(*(double *)src, max));
    }
    return (out);
}
