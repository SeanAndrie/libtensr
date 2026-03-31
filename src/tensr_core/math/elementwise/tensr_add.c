/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:38:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 20:34:19 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>
#include <tensr_core/core_math.h>
#include <utils/tensr_callbacks.h>

t_tensr *tensr_add(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
    if (!a || !b)
        return (NULL);
    out = tensr_elementwise(a, b, add_func, out);
    if (!out)
        return (NULL);
    return (out);
}
