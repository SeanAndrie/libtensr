/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_matmul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:44:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/13 18:47:34 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_math.h>

static t_bool	is_compatible(const t_layout *a, const t_layout *b)
{
	if (a->ndim != 2 || b->ndim != 2)
		return (FALSE);
	if (a->shape[1] != b->shape[0])
		return (FALSE);
	return (TRUE);
}

static t_slice	slice_init(const int inner_dim)
{
	return ((t_slice){.axis = 1, .start = 0, .end = inner_dim, .step = 1});
}

static void	*calculate_entry(const t_tensr *a, const t_tensr *b,
		t_slice *a_slices, t_slice *b_slices)
{
	t_tensr	*a_s;
	t_tensr	*b_s;
	t_tensr	*dot;

	a_s = tensr_slice(a, 2, a_slices);
	if (!a_s)
		return (NULL);
	b_s = tensr_slice(b, 2, b_slices);
	if (!b_s)
	{
		tensr_free(a_s);
		return (NULL);
	}
	dot = tensr_inner(a_s, b_s, 2, (size_t[]){0, 1});
	tensr_free(b_s);
	tensr_free(a_s);
	return (dot);
}

static t_bool	fill_out(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
	int		i;
	int		j;
	t_tensr	*dot;
	t_slice	a_slices[2];
	t_slice	b_slices[2];

	i = -1;
	a_slices[1] = slice_init(a->layout.shape[1]);
	b_slices[1] = slice_init(b->layout.shape[1]);
	while (++i < (int)out->layout.shape[0])
	{
		a_slices[0] = (t_slice){0, i, i + 1, 1};
		j = -1;
		while (++j < (int)out->layout.shape[1])
		{
			b_slices[0] = (t_slice){0, j, j + 1, 1};
			dot = calculate_entry(a, b, a_slices, b_slices);
			if (!dot)
				return (FALSE);
			if (!tensr_set(out, dot->data, (size_t[]){i, j}))
				return (tensr_free(dot), FALSE);
			tensr_free(dot);
		}
	}
	return (TRUE);
}

static t_tensr	*initialize(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
	t_tensr	*ret;

	if (out)
		ret = out;
	else
	{
		ret = tensr_alloc(2, (size_t[]){a->layout.shape[0], b->layout.shape[1]},
				a->dtype);
		if (!ret)
			return (NULL);
	}
	return (ret);
}

t_tensr	*tensr_matmul(const t_tensr *a, const t_tensr *b, t_tensr *out)
{
	t_bool	ok;
	t_tensr	*b_t;

	if (!a || !b || a->dtype != b->dtype || !is_compatible(&a->layout,
			&b->layout))
		return (NULL);
	out = initialize(a, b, out);
	if (!out)
		return (NULL);
	b_t = tensr_transpose(b);
	if (!b_t)
	{
		tensr_free(out);
		return (NULL);
	}
	ok = fill_out(a, b_t, out);
	tensr_free(b_t);
	if (!ok)
	{
		tensr_free(out);
		return (NULL);
	}
	return (out);
}
