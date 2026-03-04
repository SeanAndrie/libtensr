/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reshape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 00:15:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/20 14:56:00 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

t_tensr *tensr_reshape(const t_tensr *t, const int ndim, size_t *shape)
{
    int             i;
    t_tensr         *v;
    t_layout        layout;

    if (!t || ndim <= 0 || !shape)
        return (NULL);
    if (!layout_alloc(ndim, &layout))
        return (NULL);
    layout.stride[ndim - 1] = 1;
    i = ndim - 2;
    while (i >= 0)
    {
        layout.stride[i] = layout.stride[i + 1] * shape[i + 1];
        i--;
    }
    layout.shape = shape;
    v = tensr_view(t, t->data, &layout);
    layout_free(&layout);
    return (v);
}
