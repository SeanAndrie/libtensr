/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:07:32 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/13 15:44:47 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>
#include <tensr.h>

size_t	tensr_compute_offset(const t_tensr *t, size_t ndim,
		const size_t *indices)
{
	size_t	i;
	size_t	idx;
	ssize_t	diff;
	size_t	offset;

	if (!t || !indices)
		return (0);
	diff = (ssize_t)ndim - (ssize_t)t->ndim;
	offset = 0;
	i = 0;
	while (i < t->ndim)
	{
		if ((ssize_t)i + diff < 0 || t->shape[i] == 1)
			idx = 0;
		else
			idx = indices[(ssize_t)i + diff];
		offset += idx * t->stride[i];
		i++;
	}
	return (offset);
}

bool	tensr_set(t_tensr *t, size_t ndim, const size_t *indices, void *value)
{
	unsigned char	*base;

	if (!t || !indices || !value || !t->data)
		return (false);
	base = (unsigned char *)t->data + tensr_compute_offset(t, ndim, indices);
	ft_memcpy(base, value, t->itemsize);
	return (true);
}

bool	tensr_get(t_tensr *t, size_t ndim, const size_t *indices, void *value)
{
	unsigned char	*base;

	if (!t || !indices || !value || !t->data)
		return (false);
	base = (unsigned char *)t->data + tensr_compute_offset(t, ndim, indices);
	ft_memcpy(value, base, t->itemsize);
	return (true);
}

void	next_coords(size_t *coords, const size_t *shape, size_t ndim)
{
	ssize_t	i;

	i = ndim - 1;
	while (i >= 0)
	{
		coords[i]++;
		if (coords[i] < shape[i])
			return ;
		coords[i] = 0;
		--i;
	}
}

t_tensr	*tensr_elementwise(t_tensr *a, t_tensr *b, void (*f)(void *, void *,
			void *, t_dtype))
{
	ssize_t		i;
	t_op_ctx	ctx;
	t_tensr		*out;

	ft_memset(&ctx, 0, sizeof(ctx));
	if (!infer_bcast_shape(a, b, &ctx.ndim, ctx.shape))
		return (NULL);
	out = tensr_create(ctx.ndim, ctx.shape, a->dtype);
	if (!out)
		return (NULL);
	ft_memset(ctx.out_indices, 0, sizeof(ctx.out_indices));
	i = -1;
	while (++i < (ssize_t)out->size)
	{
		f((unsigned char *)a->data + tensr_compute_offset(a, ctx.ndim,
				ctx.out_indices), (unsigned char *)b->data
			+ tensr_compute_offset(b, ctx.ndim, ctx.out_indices),
			(unsigned char *)out->data + tensr_compute_offset(out, ctx.ndim,
				ctx.out_indices), a->dtype);
		next_coords(ctx.out_indices, ctx.shape, ctx.ndim);
	}
	return (out);
}
