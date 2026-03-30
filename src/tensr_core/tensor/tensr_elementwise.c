/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_elementwise.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:44:39 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/09 16:36:56 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

static void	map_indices(const int out_ndim, const t_layout *t_l,
		size_t *t_indices, const size_t *out_indices)
{
	int	i;
	int	t_dim;

	i = 0;
	while (i < out_ndim)
	{
		t_dim = i + (t_l->ndim - out_ndim);
		// if target_dim exists in broadcasted output
		if (t_dim >= 0)
		{
			// if dimension is 1, broadcast to 0
			if (t_l->shape[t_dim] == 1)
				t_indices[t_dim] = 0;
			// set placeholder index to broadcast index
			else
				t_indices[t_dim] = out_indices[i];
		}
		i++;
	}
}

static void	init_indices(size_t *a_indices, size_t *b_indices, int a_ndim,
		int b_ndim)
{
	ft_memset(a_indices, 0, sizeof(size_t) * a_ndim);
	ft_memset(b_indices, 0, sizeof(size_t) * b_ndim);
}

static t_tensr	*tensr_out(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
	t_tensr	*res;

	if (!a || !b || a->dtype != b->dtype)
		return (NULL);
	if (out)
		res = out;
	else
	{
		res = tensr_broadcast(&a->layout, &b->layout, a->dtype);
		if (!res)
			return (NULL);
	}
	return (res);
}

t_tensr	*tensr_elementwise(const t_tensr *a, const t_tensr *b, t_tensr *out,
		void (*f)(void *a, void *b, void *out, t_dtype dtype))
{
	t_iter	it;
	t_tensr	*res;
	size_t	a_indices[MAX_NDIM];
	size_t	b_indices[MAX_NDIM];

	res = tensr_out(a, b, out);
	if (!res)
		return (NULL);
	if (!iter_init(&res->layout, &it))
	{
		if (!out)
			tensr_free(res);
		return (NULL);
	}
	init_indices(a_indices, b_indices, a->layout.ndim, b->layout.ndim);
	while (iter_next(&it))
	{
		map_indices(res->layout.ndim, &a->layout, a_indices, it.indices);
		map_indices(res->layout.ndim, &b->layout, b_indices, it.indices);
		f(tensr_get(a, a_indices), tensr_get(b, b_indices), tensr_get(res,
				it.indices), a->dtype);
	}
	return (res);
}
