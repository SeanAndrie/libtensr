/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elemwise_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:33:16 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/13 15:47:45 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tensr.h>
#include <linalg.h>

static void add(void *a, void *b, void *c, t_dtype dtype)
{
    if (dtype == DTYPE_INT)
        *(int *)c = *(int *)a + *(int *)b;
    else if (dtype == DTYPE_FLOAT)
        *(float*)c = *(float *)a + *(float *)b;
    else if (dtype == DTYPE_DOUBLE)
        *(double *)c = *(double *)a + *(double *)b;
}

t_tensr *tensr_add(t_tensr *a, t_tensr *b)
{
    t_tensr *c;
    
	if (!a || !b || !a->data || !b->data || a->dtype != b->dtype)
		return (NULL);
    c = tensr_elementwise(a, b, add);
    if (!c)
        return (NULL);
    return (c);
}
