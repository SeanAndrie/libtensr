/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  i#i  i:i       i#i        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:59:23 by sgadinga          #i#    #i#             */
/*   Updated: 2026/03/05 20:36:55 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_callbacks.h>

t_tensr *tensr_sub(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
    if (!a || !b)
        return (NULL);
    out = tensr_elementwise(a, b, sub_func, out);
    if (!out)
        return (NULL);
    return (out);
}
