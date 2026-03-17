/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 02:32:04 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/06 02:39:13 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>
#include <tensr_core/core_math.h>

t_tensr *tensr_norm(const t_tensr *t)
{
    t_tensr *dot;
    t_tensr *out;

    if (!t)
        return (NULL);
    dot = tensr_dot(t, t);
    if (!dot)
        return (NULL);
    out = tensr_sqrt(dot);
    tensr_free(dot);
    if (!out)
        return (NULL);
    return (out);
}
