/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:09:33 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 18:44:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <utils/tensr_debug.h>

static void	print_elem(const void *data, t_dtype dtype, size_t byte_off)
{
	const char	*ptr;

	ptr = (const char *)data + byte_off;
	if (dtype == DT_U8)
		ft_printf("%u", (unsigned int)*(const uint8_t *)ptr);
	else if (dtype == DT_I32)
		ft_printf("%d", *(const int32_t *)ptr);
	else if (dtype == DT_I64)
		ft_printf("%d", *(const int64_t *)ptr);
	else if (dtype == DT_F32)
		ft_printf("%f", (double)*(const float *)ptr);
	else if (dtype == DT_F64)
		ft_printf("%f", *(const double *)ptr);
	else if (dtype == DT_C64)
		print_c64(ptr);
	else if (dtype == DT_C128)
		print_c128(ptr);
	else
		ft_printf("?");
}

static void	print_indent(int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		ft_printf(" ");
		i++;
	}
}

static void	print_sep(int is_last_dim)
{
	ft_printf(",");
	if (is_last_dim)
		ft_printf(" ");
	else
		ft_printf("\n");
}

static void	print_recursive(const t_tensr *t, size_t base_off, int dim)
{
	size_t	i;
	size_t	step;
	size_t	last;
	int		is_last_dim;

	step = t->layout.stride[dim] * t->elemsize;
	last = t->layout.shape[dim];
	is_last_dim = (dim == t->layout.ndim - 1);
	ft_printf("[");
	i = 0;
	while (i < last)
	{
		if (is_last_dim)
			print_elem(t->data, t->dtype, base_off + i * step);
		else
		{
			if (i > 0)
				print_indent(7 + dim + 1);
			print_recursive(t, base_off + i * step, dim + 1);
		}
		if (i++ < last - 1)
			print_sep(is_last_dim);
	}
	ft_printf("]");
}

void	tensr_print(t_tensr *t)
{
	if (!t || !t->data)
		return ;
	ft_printf("\ntensor(");
	if (t->layout.ndim == 0)
		print_elem(t->data, t->dtype, 0);
	else
		print_recursive(t, 0, 0);
	ft_printf(")\n");
}
