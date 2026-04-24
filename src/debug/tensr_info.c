/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:14:16 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 19:10:18 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <utils/tensr_debug.h>

static void	print_arr(const int ndim, const size_t *arr)
{
	int	i;

	if (ndim == 0 || !arr)
		return ;
	i = 0;
	ft_printf("{");
	while (i < ndim)
	{
		ft_printf("%u", arr[i]);
		if ((i + 1) < ndim)
			ft_printf(", ");
		i++;
	}
	ft_printf("}\n");
}

static void	print_dtype(t_dtype dtype)
{
	ft_printf("dtype: ");
	if (dtype == DT_I32)
		ft_printf("I32");
	else if (dtype == DT_I64)
		ft_printf("I64");
	else if (dtype == DT_F32)
		ft_printf("F32");
	else if (dtype == DT_F64)
		ft_printf("F64");
	else if (dtype == DT_C64)
		ft_printf("C64");
	else if (dtype == DT_C128)
		ft_printf("C128");
	else
		ft_printf("Unknown");
	ft_printf("\n");
}

void	tensr_info(const char *name, t_tensr *t)
{
	if (!t)
		return ;
	ft_printf("\n");
	if (name)
	{
		ft_printf("%s\n", name);
		while (*name)
		{
			ft_printf("-");
			name++;
		}
		ft_printf("\n");
	}
	ft_printf("size: %u\n", t->size);
	ft_printf("elemsize: %u\n", t->elemsize);
	if (t->layout.ndim > 0)
	{
		ft_printf("ndim: %d\n", t->layout.ndim);
		ft_printf("shape: ");
		print_arr(t->layout.ndim, t->layout.shape);
		ft_printf("stride: ");
		print_arr(t->layout.ndim, t->layout.stride);
	}
	print_dtype(t->dtype);
	tensr_print(t);
}
