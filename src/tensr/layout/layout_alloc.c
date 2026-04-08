/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_alloc.c                                     :+:      ::::::::   */
/*                                                    +:+ +:+         +:     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +:++:+                   */
/*   Created: 2026/02/20 14:14:59 by sgadinga          #+#    #+#              */
/*   Updated: 2026/04/08 23:30:00 by sgadinga         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/core.h>

bool layout_alloc(const int ndim, t_layout *l)
{
    if (!l)
        return (false);
    ft_memset(l, 0, sizeof(t_layout));
    l->ndim = ndim;
    l->shape = l->shape_buf;
    l->stride = l->stride_buf;
    return (true);
}
