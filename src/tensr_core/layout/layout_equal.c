/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 00:28:30 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 01:13:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

bool    layout_equal(const t_layout *a, const t_layout *b)
{
    int i;

    if (!a || !b || a->ndim != b->ndim)
        return (false);
    i = a->ndim - 1;
    while (i >= 0)
    {
        if (a->shape[i] != b->shape[i])
            return (false);
        i--;
    }
    return (true);
}
