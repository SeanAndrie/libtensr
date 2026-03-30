/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_div.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 23:02:44 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 20:42:37 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>
#include <tensr_core/core_math.h>
#include <utils/tensr_callbacks.h>

t_tensr *tensr_div(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
    if (!a || !b)
        return (NULL);
    out = tensr_elementwise(a, b, out, div_func);
    if (!out)
        return (NULL);
    return (out);
}
