/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_slice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:10:47 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/27 18:15:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/tensr.h>

static bool	slices_are_valid(const t_tensr *t, const int n_slices,
		const t_slice *slices)
{
	int		i;
	int		axis;
	bool	used_axes[MAX_NDIM];

	ft_memset(used_axes, 0, sizeof(used_axes));
	i = 0;
	while (i < n_slices)
	{
		axis = slices[i].axis;
		if (axis < 0 || axis >= t->layout.ndim)
			return (false);
		if (used_axes[axis])
			return (false);
		if (slices[i].step == 0)
			return (false);
		if (slices[i].start >= slices[i].end)
			return (false);
		if (slices[i].end > t->layout.shape[axis])
			return (false);
		used_axes[axis] = true;
		i++;
	}
	return (true);
}

static size_t	calculate_base_offset(const int n_slices, const t_slice *slices,
		size_t *shape, size_t *stride)
{
	int		i;
	int		axis;
	size_t	offset;
	size_t	orig_stride;

	i = 0;
	offset = 0;
	while (i < n_slices)
	{
		axis = slices[i].axis;
		orig_stride = stride[axis];
		shape[axis] = (slices[i].end - slices[i].start + slices[i].step - 1)
			/ slices[i].step;
		offset += slices[i].start * orig_stride;
		stride[axis] *= slices[i].step;
		i++;
	}
	return (offset);
}

t_tensr	*tensr_slice(const t_tensr *t, const int n_slices,
		const t_slice *slices)
{
	t_tensr		*v;
	t_layout	layout;
	size_t		offset;

	if (!t || n_slices <= 0 || !slices || !slices_are_valid(t, n_slices,
			slices))
		return (NULL);
	if (!layout_alloc(t->layout.ndim, &layout))
		return (NULL);
	ft_memcpy(layout.shape, t->layout.shape, sizeof(size_t) * t->layout.ndim);
	ft_memcpy(layout.stride, t->layout.stride, sizeof(size_t) * t->layout.ndim);
	offset = calculate_base_offset(n_slices, slices, layout.shape,
			layout.stride);
	v = tensr_view(t, (void *)((char *)t->data + offset * t->elemsize),
			&layout);
    layout_free(&layout);
	return (v);
}
