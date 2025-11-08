/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtensr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:14:54 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/07 16:08:23 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_H
# define TENSR_H

#include <libft.h>
#include <limits.h>

# define MAX_DIM 32

typedef enum s_dtype
{
    DTYPE_INT,
    DTYPE_FLOAT,
    DTYPE_DOUBLE
}   t_dtype;

typedef struct s_tensr
{
    size_t          ndim;       // e.g. 3 for (2, 3, 4)
    size_t          size;       // total number of elements
    t_dtype         dtype;      // item data type
    void            *data;
    size_t          *shape;     // array of dimension lengths
    size_t          *stride;    // byte step per dimension
    size_t          itemsize;   // size per element
}                   t_tensr;

void        free_tensr(t_tensr *tensr);

size_t      tensr_offset(const t_tensr *t, const size_t *indices);
bool        tensr_set(t_tensr *t, const size_t *indices, void *value);
bool        tensr_get(t_tensr *t, const size_t *indices, void *value);

t_tensr     *tensr_create(const size_t ndim, const size_t *shape, t_dtype type);

#endif
