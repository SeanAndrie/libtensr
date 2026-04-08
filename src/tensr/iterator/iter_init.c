/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_init.c                                        :::      ::::::::   */
/*                                                    :::      ::::::::   */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  #+#    #+#             */
/*                                                  #+#    #+#             */
/*   Created: 2026/02/02 15:57:16 by sgadinga          #+#   #+#+#          */
/*   Updated: 2026/04/09 02:00:00 by sgadinga         ###    ########       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

bool    iter_init(const t_tensr *t, t_iter *it)
{
	int	i;

	if (!t)
	{
		ft_dprintf(STDERR_FILENO,
			"libtensr: iter_init: tensor is missing\n");
		return (false);
	}
	else if (!it)
	{
		ft_dprintf(STDERR_FILENO,
			"libtensr: iter_init: iterator is missing\n");
		return (false);
	}
	it->total = 1;
	i = 0;
	while (i < t->layout.ndim)
		it->total *= t->layout.shape[i++];
	it->layout = (t_layout *)&t->layout;
	it->counter = 0;
	ft_memset(it->indices, 0, sizeof(it->indices));
	it->contiguous = tensr_is_contiguous(t);
	it->tensor = t;
	it->data_ptr = t->data;
	return (true);
}