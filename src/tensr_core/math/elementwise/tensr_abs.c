/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_abs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:35:54 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/08 03:14:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <tensr_core/core.h>
#include <tensr_core/core_math.h>

t_tensr	*tensr_abs(const t_tensr *t)
{
    t_iter			it;
    t_tensr			*out;
    void            *src;
    void            *dst;

    out = tensr_alloc(t->layout.ndim, t->layout.shape, t->dtype);
    if (!out)
        return (NULL);
    if (!iter_init(&out->layout, &it))
        return (tensr_free(out), NULL);
    while (iter_next(&it))
    {
        src = tensr_get(t, it.indices);
        dst = tensr_get(out, it.indices);
        if (t->dtype == DT_U8)
            *(uint8_t *)dst = *(uint8_t *)src;
        else if (t->dtype == DT_I32)
            *(int32_t *)dst = abs(*(int32_t *)src);
        else if (t->dtype == DT_I64)
            *(int64_t *)dst = llabs(*(int64_t *)src);
        else if (t->dtype == DT_F32)
            *(float *)dst = fabsf(*(float *)src);
        else if (t->dtype == DT_F64)
            *(double *)dst = fabs(*(double *)src);
    }
    return (out);
}
