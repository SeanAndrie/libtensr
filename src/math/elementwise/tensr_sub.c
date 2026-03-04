/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  i#i  i:i       i#i        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:59:23 by sgadinga          #i#    #i#             */
/*   Updated: 2026/02/03 23:34:05 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>

static void *sub_func(void *a, void *b, t_dtype dtype)
{
    static t_result res;

    if (dtype == DT_I32)
    {
        res.i = *(int *)a - *(int *)b;
        return (&res.i);
    }
    else if (dtype == DT_I64)
    {
        res.l = *(long long *)a - *(long long *)b;
        return (&res.l);
    }
    else if (dtype == DT_F32)
    {
        res.f = *(float *)a - *(float *)b;
        return (&res.f);
    }
    else if (dtype == DT_F64)
    {
        res.d = *(double *)a - *(double *)b;
        return (&res.d);
    }
    return (NULL);
}

t_tensr *tensr_sub(const t_tensr *a, const t_tensr *b)
{
    t_tensr *out;

    if (!a || !b)
        return (NULL);
    out = tensr_elementwise(a, b, sub_func);
    if (!out)
        return (NULL);
    return (out);
}
