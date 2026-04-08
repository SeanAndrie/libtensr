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

#include <tensr/tensr.h>
#include <tensr/callbacks.h>

t_tensr *tensr_div(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
    if (!a || !b)
        return (NULL);
    out = tensr_elementwise(a, b, div_func, out);
    if (!out)
        return (NULL);
    return (out);
}
