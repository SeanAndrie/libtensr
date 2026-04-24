/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:18:59 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 02:50:32 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_MATH_H
# define TENSR_MATH_H

# include <tensr/tensr.h>
# include <utils/tensr_callbacks.h>

/* Reduction operation descriptor */
typedef struct s_reduce_op
{
	void				(*init)(void *acc, t_dtype dtype);
	void				(*apply)(void *acc, const void *value, t_dtype dtype);
	void				(*finalize)(void *acc, size_t count, t_dtype dtype);
}						t_reduce_op;

typedef struct s_reduce_ctx
{
	struct s_iter		inner;
	struct s_iter		outer;
	size_t				base_off;
	struct s_layout		reduced_l;
	struct s_reduce_op	reduce_op;
	enum e_bool			is_reduced[MAX_NDIM];
}						t_reduce_ctx;

typedef struct s_argcc
{
	int64_t				idx;
	void				*value;
}						t_argcc;

t_reduce_ctx			*tensr_reduce_ctx(const int n_axes, const size_t *axes,
							t_reduce_op op);

t_tensr					*tensr_arg(const t_tensr *t, const int n_axes,
							const size_t *axes, t_bool (*cmp)(const void *a,
								const void *b, t_dtype dtype));

t_tensr					*tensr_argmax(const t_tensr *t, const int n_axes,
							const size_t *axes);

// Elementwise Operations

/*
 ** Applies an element-wise binary operation to two tensors.
 **
 ** Both tensors must have compatible shapes (broadcastable).
 ** The result tensor will have the broadcasted shape.
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 ** @param f         Binary operation function pointer.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_elementwise(const t_tensr *a, const t_tensr *b,
							void (*f)(void *a, void *b, void *out,
								t_dtype dtype), t_tensr *out);

/*
 ** Computes the absolute value of each element in the tensor.
 **
 ** @param t         Pointer to the input tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 **                  For complex tensors, returns the magnitude (cabs).
 */
t_tensr					*tensr_abs(const t_tensr *t, t_tensr *out);

/*
 ** Negates each element in the tensor.
 **
 ** @param t         Pointer to the input tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_neg(const t_tensr *t, t_tensr *out);

/*
 ** Computes the square root of each element in the tensor.
 **
 ** @param t         Pointer to the input tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_sqrt(const t_tensr *t, t_tensr *out);

/*
 ** Adds two tensors element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_add(const t_tensr *a, const t_tensr *b,
							t_tensr *out);

/*
 ** Multiplies two tensors element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_mul(const t_tensr *a, const t_tensr *b,
							t_tensr *out);

/*
 ** Subtracts tensor b from tensor a element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_sub(const t_tensr *a, const t_tensr *b,
							t_tensr *out);

/*
 ** Divides tensor a by tensor b element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the numerator tensor.
 ** @param b         Pointer to the denominator tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_div(const t_tensr *a, const t_tensr *b,
							t_tensr *out);

/*
 ** Clamps each element in the tensor between min and max values.
 **
 ** @param t         Pointer to the input tensor.
 ** @param min       Minimum value (inclusive).
 ** @param max       Maximum value (inclusive).
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_clamp(const t_tensr *t, double min, double max,
							t_tensr *out);

// Reduction Operations

/*
** Reduces a tensor along specified axes using a strided reduction strategy.
**
** This is an internal function that handles the actual reduction logic
** with support for non-contiguous tensors and custom reduction contexts.
**
** @param t         Pointer to the source tensor.
** @param n_axes    Number of axes to reduce.
** @param axes     Array of axis indices to reduce.
** @param ctx      Reduction context (init, apply, finalize functions).
** @return         A pointer to the reduced tensor, or NULL on failure.
*/
t_tensr					*tensr_reduce_strided(const t_tensr *t,
							const int n_axes, const size_t *axes,
							t_reduce_ctx *ctx);

/*
 ** Reduces a tensor along specified axes.
 **
 ** Reduction operations collapse one or more dimensions by applying
 ** an aggregation function (e.g., sum, mean, min, max).
 **
 ** @param t         Pointer to the source tensor.
 ** @param n_axes    Number of axes to reduce.
 ** @param axes      Array of axis indices to reduce.
 ** @param op        Reduction operation descriptor (init, apply, finalize).
 **
 ** @return          A pointer to the reduced tensor, or NULL on failure.
 */
t_tensr					*tensr_reduce(const t_tensr *t, const int n_axes,
							const size_t *axes, t_reduce_op op);

/*
 ** Computes the sum of elements along specified axes.
 **
 ** @param t         Pointer to the input tensor.
 ** @param n_axes    Number of axes to reduce.
 ** @param axes      Array of axis indices to reduce.
 **
 ** @return          A pointer to the reduced tensor, or NULL on failure.
 */
t_tensr					*tensr_sum(const t_tensr *t, const int n_axes,
							const size_t *axes);

/*
 ** Computes the maximum of elements along specified axes.
 **
 ** @param t         Pointer to the input tensor.
 ** @param n_axes    Number of axes to reduce.
 ** @param axes      Array of axis indices to reduce.
 **
 ** @return          A pointer to the reduced tensor, or NULL on failure.
 */
t_tensr					*tensr_max(const t_tensr *t, const int n_axes,
							const size_t *axes);

/*
 ** Computes the minimum of elements along specified axes.
 **
 ** @param t         Pointer to the input tensor.
 ** @param n_axes    Number of axes to reduce.
 ** @param axes      Array of axis indices to reduce.
 **
 ** @return          A pointer to the reduced tensor, or NULL on failure.
 */
t_tensr					*tensr_min(const t_tensr *t, const int n_axes,
							const size_t *axes);

/*
 ** Computes the mean of elements along specified axes.
 **
 ** @param t         Pointer to the input tensor.
 ** @param n_axes    Number of axes to reduce.
 ** @param axes      Array of axis indices to reduce.
 **
 ** @return          A pointer to the reduced tensor, or NULL on failure.
 */
t_tensr					*tensr_mean(const t_tensr *t, const int n_axes,
							const size_t *axes);

// Linear Algebra Operations

/*
 ** Computes the L2 norm (Euclidean norm) of the tensor.
 **
 ** @param t         Pointer to the input tensor.
 ** @param keepdims  Whether to keep reduced dimensions.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the scalar result tensor, or NULL on failure.
 */
t_tensr					*tensr_norm(const t_tensr *t, t_bool keepdims,
							t_tensr *out);

/*
 ** Computes the inner product of two tensors.
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 ** @param n_axes    Number of axes to contract.
 ** @param axes      Array of axis indices to contract.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_inner(const t_tensr *a, const t_tensr *b,
							const size_t n_axes, const size_t *axes);

/*
 ** Computes the cross product of two 3-D tensors.
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_cross(const t_tensr *a, const t_tensr *b);

/*
 ** Performs matrix multiplication of two tensors.
 **
 ** @param a         Pointer to the first tensor (matrix).
 ** @param b         Pointer to the second tensor (matrix).
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_matmul(const t_tensr *a, const t_tensr *b);

/*
 ** Normalizes the tensor to unit length (L2 norm = 1).
 **
 ** @param t         Pointer to the input tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the normalized tensor, or NULL on failure.
 */
t_tensr					*tensr_normalize(const t_tensr *t, t_tensr *out);

/*
 ** Scales each element in the tensor by a constant value.
 **
 ** @param t         Pointer to the input tensor.
 ** @param value     The scaling factor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_scale(const t_tensr *t, double value,
							t_tensr *out);

/*
 ** Computes the dot product of two tensors.
 **
 ** Both tensors must be 1-D or compatible for broadcasting.
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_dot(const t_tensr *a, const t_tensr *b);

#endif
