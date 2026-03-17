/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_metadata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:32:56 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 20:30:00 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>
#include <utils/tensr_debug.h>

static void print_array(const char *fieldname, size_t *arr, int ndim)
{
    printf(" + %s: {", fieldname);
    for (int i = 0; i < ndim; i++)
    {
        printf("%zu", arr[i]);
        if (i < ndim - 1)
            printf(", ");
    }
    printf("}\n");
}

static void print_dtype(t_dtype dtype)
{
    printf(" + dtype: ");
    if (dtype == DT_U8)
        printf("DT_U8");
    else if (dtype == DT_I32)
        printf("DT_I32");
    else if (dtype == DT_F32)
        printf("DT_F32");
    else if (dtype == DT_I64)
        printf("DT_I64");
    else if (dtype == DT_F64)
        printf("DT_F64");
    else
        printf("Invalid Datatype");
    printf("\n");
}

void tensr_metadata(const char *name, t_tensr *t)
{
    if (!t)
        return ;
    if (name)
    {
        printf("%s:\n", name);
        for (size_t i = 0; i < ft_strlen(name) + 1; i++)
            printf("-");
        printf("\n");
    }
    printf(" + ndim: %d\n", t->layout.ndim);
    printf(" + size: %zu\n", t->size);
    printf(" + elemsize: %zu\n", t->elemsize);
    if (t->layout.ndim > 0)
    {
        print_array("shape", t->layout.shape, t->layout.ndim);
        print_array("stride", t->layout.stride, t->layout.ndim);
    }
    print_dtype(t->dtype);
    printf("\n");
}
