/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_sqrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 01:57:22 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/06 02:42:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <tensr_core/core.h>
#include <tensr_core/core_math.h>

t_tensr *tensr_sqrt(const t_tensr *t)
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
        if (out->dtype == DT_F32)
            *(float *)dst = sqrt(*(float *)src);
        else if (out->dtype == DT_F64)
            *(double *)dst = sqrt(*(double *)src);
    }
    return (out);
}
