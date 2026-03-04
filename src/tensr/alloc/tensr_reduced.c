/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_reduced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:28:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/27 15:45:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr_debug.h>
#include <core/tensr.h>

// t_tensr	*tensr_reduced(const t_layout *l, const int n_axes, const size_t *axes,
// 		t_dtype dtype)
// {
// 	int		i;
// 	int		j;
// 	size_t	*shape;
// 	int		out_dim;
// 	t_tensr	*reduced;
//
// 	if (!l || !axes || n_axes <= 0 || n_axes >= l->ndim)
// 		return (NULL);
// 	shape = malloc(sizeof(size_t) * (l->ndim - n_axes));
// 	if (!shape)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	out_dim = 0;
// 	while (++i < l->ndim)
// 	{
// 		if (j < n_axes && (int)axes[j] == i)
// 			j++;
// 		else
// 			shape[out_dim++] = l->shape[i];
// 	}
// 	reduced = tensr_alloc((l->ndim - n_axes), shape, dtype);
// 	free(shape);
// 	return (reduced);
// }

t_tensr *tensr_reduced(const t_layout *l, const int n_axes, const size_t *axes, t_dtype dtype)
{
    int         i;
    int         j;
    t_tensr     *out;
    t_layout    layout;
    int         out_dim;
    
    if (!l || !axes || n_axes <= 0)
        return (NULL);
    if (!layout_alloc(l->ndim - n_axes, &layout))
        return (tensr_alloc(0, NULL, dtype));
    i = -1;
    j = 0;
    out_dim = 0;
    while (++i < l->ndim)
    {
        if (j < n_axes && (int)axes[j] == i)
            j++;
        else
            layout.shape[out_dim++] = l->shape[i];
    }
    out = tensr_alloc(layout.ndim, layout.shape, dtype);
    layout_free(&layout);
    return (out);
}
