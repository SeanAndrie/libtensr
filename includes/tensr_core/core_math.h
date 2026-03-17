/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:49:08 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/15 21:45:16 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_MATH_H
# define TENSR_MATH_H

# include <tensr_core/core.h>

// Elementwise Operations

/*
 ** Computes the absolute value of each element in the tensor.
 **
 ** @param t         Pointer to the input tensor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr                 *tensr_abs(const t_tensr *t);

/*
 ** Negates each element in the tensor.
 **
 ** @param t         Pointer to the input tensor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_neg(const t_tensr *t);

/*
 ** Computes the square root of each element in the tensor.
 **
 ** @param t         Pointer to the input tensor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_sqrt(const t_tensr *t);

/*
 ** Adds two tensors element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_add(const t_tensr *a, const t_tensr *b);

/*
 ** Multiplies two tensors element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_mul(const t_tensr *a, const t_tensr *b);

/*
 ** Subtracts tensor b from tensor a element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_sub(const t_tensr *a, const t_tensr *b);

/*
 ** Divides tensor a by tensor b element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the numerator tensor.
 ** @param b         Pointer to the denominator tensor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr					*tensr_div(const t_tensr *a, const t_tensr *b);

/*
 ** Clamps each element in the tensor between min and max values.
 **
 ** @param t         Pointer to the input tensor.
 ** @param min       Minimum value (inclusive).
 ** @param max       Maximum value (inclusive).
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr                 *tensr_clamp(const t_tensr *t, double min, double max);

// Reductions Operations

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
t_tensr                 *tensr_mean(const t_tensr *t, const int n_axes,
                            const size_t *axes);

// Linear Algebra Operations

/*
 ** Computes the L2 norm (Euclidean norm) of the tensor.
 **
 ** @param t         Pointer to the input tensor.
 **
 ** @return          A pointer to the scalar result tensor, or NULL on failure.
 */
t_tensr                 *tensr_norm(const t_tensr *t);

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
t_tensr                 *tensr_matmul(const t_tensr *a, const t_tensr *b);

/*
 ** Normalizes the tensor to unit length (L2 norm = 1).
 **
 ** @param t         Pointer to the input tensor.
 **
 ** @return          A pointer to the normalized tensor, or NULL on failure.
 */
t_tensr                 *tensr_normalize(const t_tensr *t);

/*
 ** Scales each element in the tensor by a constant value.
 **
 ** @param t         Pointer to the input tensor.
 ** @param value     The scaling factor.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr	                *tensr_scale(const t_tensr *t, double value);

#endif
