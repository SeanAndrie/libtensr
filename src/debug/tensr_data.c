/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:20:36 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/13 15:22:22 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <tensr.h>
#include <debug.h>

static void print_cast_data(t_tensr *t, size_t *indices) 
{
    int     temp_int;
    float   temp_float;
    double  temp_double;

    if (t->dtype == DTYPE_INT)
    {
        tensr_get(t, t->ndim, indices, &temp_int);
        printf("%d", temp_int);
    }
    else if (t->dtype == DTYPE_FLOAT)
    {
        tensr_get(t, t->ndim, indices, &temp_float);
        printf("%f", temp_float);
    }
    else if (t->dtype == DTYPE_DOUBLE)
    {
        tensr_get(t, t->ndim, indices, &temp_double);
        printf("%lf", temp_double);
    }
    printf(" ");
}

static void print_indent(size_t indent)
{
    size_t i = 0;
    while (i < indent)
    {
        printf("  ");
        i++;
    }
}

static void print_coords(size_t *indices, size_t dim)
{
    size_t i;
    
    i = 0;
    printf("[");
    while (i <= dim)
    {
        printf("%zu", indices[i]);
        if (i < dim)
            printf(", ");
        i++;
    }
    printf("]");
}

static void print_recursive(t_tensr *t, size_t *indices, size_t dim, size_t indent)
{
    size_t i;

    if (dim == t->ndim - 1)
    {
        i = 0;
        print_indent(indent);
        while (i < t->shape[dim])
        {
            indices[dim] = i;
            print_cast_data(t, indices);
            i++;
        }
        printf("\n");
        return;
    }
    i = 0;
    while (i < t->shape[dim])
    {
        indices[dim] = i;
        print_indent(indent);
        printf("Slice ");
        print_coords(indices, dim);
        printf(":\n");
        print_recursive(t, indices, dim + 1, indent + 1);
        i++;
    }
}

void tensr_data(t_tensr *t)
{
    size_t i;
    size_t indices[MAX_NDIM];

    if (!t || !t->data)
        return;
    ft_memset(indices, 0, sizeof(indices));
    printf("\ndata:\n\n");
    printf("Shape: [");
    i = 0;
    while (i < t->ndim)
    {
        printf("%zu", t->shape[i]);
        if (i + 1 < t->ndim)
            printf(", ");
        i++;
    }
    printf("]\n");
    if (t->dtype == DTYPE_INT)
        printf("Dtype: int\n\n");
    else if (t->dtype == DTYPE_FLOAT)
        printf("Dtype: float\n\n");
    else if (t->dtype == DTYPE_DOUBLE)
        printf("Dtype: double\n\n");
    print_recursive(t, indices, 0, 0);
}
