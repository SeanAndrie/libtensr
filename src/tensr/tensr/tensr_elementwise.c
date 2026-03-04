/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_elementwise.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:44:39 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/17 19:37:47 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

static void	map_indices(const int bcast_ndim, const t_layout *t_l,
		size_t *t_indices, const size_t *bcast_indices)
{
	int	i;
	int	t_dim;

	i = 0;
	while (i < bcast_ndim)
	{
		t_dim = i + (t_l->ndim - bcast_ndim);
        // if target_dim exists in broadcasted output
		if (t_dim >= 0)
		{
            // if dimension is 1, broadcast to 0
			if (t_l->shape[t_dim] == 1)
				t_indices[t_dim] = 0;
            // set placeholder index to broadcast index
			else
				t_indices[t_dim] = bcast_indices[i];
		}
		i++;
	}
}

t_tensr *tensr_elementwise(const t_tensr *a, const t_tensr *b, void *(*f)(void *a,
			void *b, t_dtype dtype))
{
	t_iter	it;
	t_tensr	*out;
	void	*result;
	size_t	a_indices[MAX_NDIM];
	size_t	b_indices[MAX_NDIM];

	if (!a || !b || a->dtype != b->dtype)
		return (NULL);
    // 1. Allocate tensor with broadcasted shape
	out = tensr_bcast(&a->layout, &b->layout, a->dtype);
	if (!out)
		return (NULL);
    // 2. Initialize placeholder indices
	ft_memset(&a_indices, 0, sizeof(size_t) * a->layout.ndim);
	ft_memset(&b_indices, 0, sizeof(size_t) * b->layout.ndim);
	if (!iter_init(&out->layout, &it))
        return (tensr_free(out), NULL);
    // 3. Iterate through broadcast dimensions
	while (iter_next(&it))
	{
        // 3.1. Map placeholder indices according to broadcast indices
		map_indices(out->layout.ndim, &a->layout, a_indices, it.indices);
		map_indices(out->layout.ndim, &b->layout, b_indices, it.indices);
        // 3.2. Apply elementwise operation
		result = f(tensr_get(a, a_indices), tensr_get(b, b_indices), a->dtype);
        // 3.3. Set result to output tensor
		if (!tensr_set(out, result, it.indices))
			return (tensr_free(out), NULL);
	}
	return (out);
}
