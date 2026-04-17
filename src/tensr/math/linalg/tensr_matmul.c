/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_matmul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:44:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/12 01:55:10 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_linalg.h>

static t_bool	is_compatible(const t_layout *a, const t_layout *b)
{
	if (a->ndim != 2 || b->ndim != 2)
		return (false);
	if (a->shape[1] != b->shape[0])
		return (false);
	return (true);
}

static void	slices_init(t_slice *a_slices, t_slice *b_slices,
		const int inner_dim)
{
	a_slices[1] = (t_slice){.axis = 1, .start = 0, .end = inner_dim, .step = 1};
	b_slices[1] = (t_slice){.axis = 1, .start = 0, .end = inner_dim, .step = 1};
}

static void	*calculate_entry(const t_tensr *a, const t_tensr *b,
		t_slice *a_slices, t_slice *b_slices)
{
	t_tensr	*a_s;
	t_tensr	*b_s;
	t_tensr	*a_1d;
	t_tensr	*b_1d;

	a_s = tensr_slice(a, 2, a_slices);
	if (!a_s)
		return (NULL);
	b_s = tensr_slice(b, 2, b_slices);
	if (!b_s)
	{
		tensr_free(a_s);
		return (NULL);
	}
	a_1d = tensr_reshape(a_s, 1, (size_t[]){a_s->size});
	b_1d = tensr_reshape(b_s, 1, (size_t[]){b_s->size});
	tensr_free(a_s);
	tensr_free(b_s);
	if (!a_1d || !b_1d)
	{
		tensr_free(a_1d);
		tensr_free(b_1d);
		return (NULL);
	}
	return (tensr_inner(a_1d, b_1d, 1, (size_t[]){0}));
}

static t_bool	fill_out(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
	int		i;
	int		j;
	t_tensr	*dot;
	t_slice	a_slices[2];
	t_slice	b_slices[2];

	i = -1;
	slices_init(a_slices, b_slices, a->layout.shape[1]);
	while (++i < (int)out->layout.shape[0])
	{
		a_slices[0] = (t_slice){0, i, i + 1, 1};
		j = -1;
		while (++j < (int)out->layout.shape[1])
		{
			b_slices[0] = (t_slice){0, j, j + 1, 1};
			dot = calculate_entry(a, b, a_slices, b_slices);
			if (!dot)
				return (false);
			if (!tensr_set(out, dot->data, (size_t[]){i, j}))
				return (tensr_free(dot), false);
			tensr_free(dot);
		}
	}
	return (true);
}

t_tensr	*tensr_matmul(const t_tensr *a, const t_tensr *b)
{
	t_tensr	*out;
	t_tensr	*b_t;

	if (!a || !b || a->dtype != b->dtype || !is_compatible(&a->layout,
			&b->layout))
		return (NULL);
	out = tensr_alloc(2, (size_t[]){a->layout.shape[0], b->layout.shape[1]},
			a->dtype);
	if (!out)
		return (NULL);
	b_t = tensr_transpose(b);
	if (!b_t)
	{
		tensr_free(out);
		return (NULL);
	}
	if (!fill_out(a, b_t, out))
	{
		tensr_free(b_t);
		tensr_free(out);
		return (NULL);
	}
	tensr_free(b_t);
	return (out);
}
