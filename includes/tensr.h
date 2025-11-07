/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 01:14:54 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/06 23:41:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef tensr_H
# define tensr_H

#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct s_tensr
{
    size_t          ndim;       // e.g. 3 for (2, 3, 4)
    size_t          size;       // total number of elements
    size_t          itemsize;   // size per element
    size_t          *shape;     // array of dimension lengths
    size_t          *stride;    // byte step per dimension
    void            *data;
}                   t_tensr;

void        free_tensr(t_tensr *tensr);

t_tensr    *tensr_create(const size_t ndim, const size_t itemsize, ...);

void        tensr_set(const t_tensr *t, const size_t *indices, void *value);
void        tensr_get(const t_tensr *t, const size_t *indices, void *value);

#endif

