/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_mul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 22:37:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 20:43:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/callbacks.h>

t_tensr *tensr_mul(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
    if (!a || !b)
        return (NULL);
    out = tensr_elementwise(a, b, mul_func, out);
    if (!out)
        return (NULL);
    return (out);
}
