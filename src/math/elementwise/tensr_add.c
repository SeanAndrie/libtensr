/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:38:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/03 23:04:03 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>

// static void *add_func(void *a, void *b, t_dtype dtype)
// {
//     static t_result res;
//
//     if (dtype == DT_I32)
//     {
//         res.i = *(int *)a + *(int *)b;
//         return (&res.i);
//     }
//     else if (dtype == DT_I64)
//     {
//         res.l = *(long long *)a + *(long long *)b;
//         return (&res.l);
//     }
//     else if (dtype == DT_F32)
//     {
//         res.f = *(float *)a + *(float *)b;
//         return (&res.f);
//     }
//     else if (dtype == DT_F64)
//     {
//         res.d = *(double *)a + *(double *)b;
//         return (&res.d);
//     }
//     return (NULL);
// }

static void add_func(void *a, void *b, void *out, t_dtype dtype)
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

t_tensr *tensr_add(const t_tensr *a, const t_tensr *b)
{
    t_tensr *out;

    if (!a || !b)
        return (NULL);
    out = tensr_elementwise(a, b, add_func);
    if (!out)
        return (NULL);
    return (out);
}
