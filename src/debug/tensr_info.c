/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:14:05 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/13 15:22:41 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <tensr.h>
#include <debug.h>

static void print_arr(size_t ndim, size_t *indices, const char *field)
{
    size_t  i;

    if (!indices || !field)
        return ;
    printf("%s: {", field);
    i = 0;
    while (i < ndim)
    {
        printf("%zu", indices[i]);
        if (i + 1 < ndim)
            printf(", ");
        i++;
    }
    printf("}\n");
}

void    tensr_info(t_tensr *t, const char *name)
{
    if (!t)
        return ;
    printf("\n");
    if (name || *name)
        printf("Tensor: %s\n----------\n", name);
    printf("ndim: %zu\n", t->ndim);
    printf("size: %zu\n", t->size);
    printf("itemsize: %zu\n", t->itemsize);
    printf("dtype: ");
    if (t->dtype == DTYPE_INT)
        printf("INT");
    else if (t->dtype == DTYPE_FLOAT)
        printf("FLOAT");
    else if (t->dtype == DTYPE_DOUBLE)
        printf("DOUBLE");
    printf("\n");
    print_arr(t->ndim, t->shape, "shape");
    print_arr(t->ndim, t->stride, "stride");
    tensr_data(t);
    printf("\n");
}

