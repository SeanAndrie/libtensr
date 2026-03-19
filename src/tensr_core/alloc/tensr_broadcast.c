/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_broadcast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:30:56 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/19 11:45:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tensr_core/core.h>

static int	get_dim(const t_layout *l, int out_ndim, int i)
{
	int	index;

	index = i + (l->ndim - out_ndim);
	if (index >= 0)
		return (l->shape[index]);
	return (1);
}

t_tensr	*tensr_broadcast(const t_layout *a, const t_layout *b, t_dtype dtype)
{
	int			i;
	t_tensr		*out;
	int			dim_a;
	int			dim_b;
	t_layout	layout;

	if (!a || !b)
		return (NULL);
	if (!layout_alloc(ft_max(a->ndim, b->ndim), &layout))
        return (NULL);
    i = layout.ndim - 1;
    while (i >= 0)
    {
		dim_a = get_dim(a, layout.ndim, i);
		dim_b = get_dim(b, layout.ndim, i);
		if (!(dim_a == dim_b || dim_a == 1 || dim_b == 1))
            return (layout_free(&layout), NULL);
		layout.shape[i--] = ft_max(dim_a, dim_b);
    }
    out = tensr_alloc(layout.ndim, layout.shape, dtype);
    layout_free(&layout);
    return (out);
}
