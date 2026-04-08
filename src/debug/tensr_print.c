/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:56:54 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/02 18:00:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_debug.h>

void	print_element(const t_tensr *t, char *data_ptr)
{
	switch (t->dtype)
	{
	case DT_U8:
		printf("%u", *(uint8_t *)data_ptr);
		break ;
	case DT_I32:
		printf("%d", *(int32_t *)data_ptr);
		break ;
	case DT_I64:
		printf("%ld", *(int64_t *)data_ptr);
		break ;
	case DT_F32:
		printf("%f", *(float *)data_ptr);
		break ;
	case DT_F64:
		printf("%lf", *(double *)data_ptr);
		break ;
	default:
		printf("?");
		break ;
	}
}

static void	tensr_print_recursive(const t_tensr *t, size_t dim, size_t *indices,
		int indent)
{
	void	*elem;

	if (dim == (size_t)t->layout.ndim)
	{
		elem = tensr_get(t, indices);
		if (!elem)
		{
			printf("?");
			return ;
		}
		print_element(t, elem);
		return ;
	}
	printf("[\n");
	for (size_t i = 0; i < t->layout.shape[dim]; i++)
	{
		for (int j = 0; j < indent + 1; j++)
			printf("  ");
		indices[dim] = i;
		tensr_print_recursive(t, dim + 1, indices, indent + 1);
		if (i + 1 < t->layout.shape[dim])
			printf(",");
		printf("\n");
	}
	for (int j = 0; j < indent; j++)
		printf("  ");
	printf("]");
}

void	tensr_print(const t_tensr *t)
{
	size_t	indices[32];

	if (!t || !t->data)
	{
		printf("Tensor is NULL or empty\n");
		return ;
	}
    ft_memset(&indices, 0, sizeof(indices));
	tensr_print_recursive(t, 0, indices, 0);
	printf("\n");
}
