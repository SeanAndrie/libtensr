/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_expand_dims.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:02:48 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/30 01:36:52 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/debug.h>

bool	tensr_expand_dims(t_tensr *t, const int axis)
{
    int         i;
    int         j;
    int         og_ndim;
    size_t      shape[MAX_NDIM];

	if (!t || axis < 0 || axis > t->layout.ndim)
        return (false);
    i = 0;
    j = 0;
    while (i < t->layout.ndim + 1)
    {
        if (i == axis)
            shape[i] = 1;
        else
            shape[i] = t->layout.shape[j++];
        i++;
    }
    og_ndim = t->layout.ndim;
    layout_free(&t->layout);
    t->size = layout_init(&t->layout, og_ndim + 1, shape);
    return (true);
}
