/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:06:52 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/10 01:15:30 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>
#include <core/tensr_math.h>

t_tensr *tensr_normalize(const t_tensr *t)
{
    t_tensr *out;
    t_tensr *norm;
    
    if (!t)
        return (NULL);
    norm = tensr_norm(t);
    if (!norm)
        return (NULL);
    out = tensr_div(t, norm);
    tensr_free(norm);
    if (!out)
        return (NULL);
    return (out);
}
