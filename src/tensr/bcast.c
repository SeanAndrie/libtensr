/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcast.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:46:11 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/13 12:38:50 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tensr.h>

static inline size_t max_size_t(size_t a, size_t b)
{
    if (a > b)
        return (a);
    return (b);
}

static inline size_t pad_dimension(t_bcast_ctx *cast, size_t *shape)
{
    if (cast->idx > 0)
        return (shape[cast->idx - 1]);
    return (1);
}

bool    infer_bcast_shape(t_tensr *a, t_tensr *b, size_t *ndim, size_t *shape)
{
    size_t      i;
    t_bcast_ctx cast_a;
    t_bcast_ctx cast_b;

    if (!a || !b)
        return (false);
    *ndim = max_size_t(a->ndim, b->ndim);
    i = 0;
    cast_a.idx = a->ndim;
    cast_b.idx = b->ndim;
    while (i < *ndim)
    {
        cast_a.dim = pad_dimension(&cast_a, a->shape);
        cast_b.dim = pad_dimension(&cast_b, b->shape);
        if (cast_a.dim != cast_b.dim && cast_a.dim != 1 && cast_b.dim != 1)
            return (false);
        shape[*ndim - 1 - i] = max_size_t(cast_a.dim, cast_b.dim);
        if (cast_a.idx > 0)
            cast_a.idx--;
        if (cast_b.idx > 0)
            cast_b.idx--;
        i++;
    }
    return (true);
}
