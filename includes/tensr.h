/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:54:54 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/13 15:37:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_H
# define TENSR_H

# define MAX_NDIM 32

typedef enum e_dtype
{
    DTYPE_INT,
    DTYPE_FLOAT,
    DTYPE_DOUBLE
}   t_dtype;

typedef struct s_tensr
{
    size_t          ndim;
    size_t          size;
    enum e_dtype    dtype;
    void            *data;
    size_t          *shape;
    size_t          *stride;
    size_t          itemsize;
}                   t_tensr;

typedef struct  s_bcast_ctx
{
    size_t      dim;
    size_t      idx;
}               t_bcast_ctx;

typedef struct  s_op_ctx
{
    size_t          ndim;
    size_t          shape[MAX_NDIM];
    size_t          out_indices[MAX_NDIM];
}                   t_op_ctx;

t_tensr     *tensr_create(const size_t ndim, const size_t *shape, t_dtype type);

bool        tensr_set(t_tensr *t, size_t ndim, const size_t *indices, void *value);
bool        tensr_get(t_tensr *t, size_t ndim, const size_t *indices, void *value);
size_t      tensr_compute_offset(const t_tensr *t, size_t ndim, const size_t *indices);

void	    next_coords(size_t *coords, const size_t *shape, size_t ndim);
t_tensr	    *tensr_elementwise(t_tensr *a, t_tensr *b, void (*f)(void *, void *, void *, t_dtype));

t_tensr     *tensr_full(const size_t ndim, size_t *shape, t_dtype dtype, void *value);

bool        infer_bcast_shape(t_tensr *a, t_tensr *b, size_t *ndim, size_t *shape);
void        free_tensr(t_tensr *tensr);

#endif

