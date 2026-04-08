/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementwise.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 23:49:13 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/08 23:49:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTWISE_H
# define ELEMENTWISE_H

/*
 ** Computes the absolute value of each element in the tensor.
 **
 ** @param t         Pointer to the input tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr	*tensr_abs(const t_tensr *t, t_tensr *out);

/*
 ** Negates each element in the tensor.
 **
 ** @param t         Pointer to the input tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr	*tensr_neg(const t_tensr *t, t_tensr *out);

/*
 ** Computes the square root of each element in the tensor.
 **
 ** @param t         Pointer to the input tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr	*tensr_sqrt(const t_tensr *t, t_tensr *out);

/*
 ** Adds two tensors element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr	*tensr_add(const t_tensr *a, const t_tensr *b, t_tensr *out);

/*
 ** Multiplies two tensors element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr	*tensr_mul(const t_tensr *a, const t_tensr *b, t_tensr *out);

/*
 ** Subtracts tensor b from tensor a element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the first tensor.
 ** @param b         Pointer to the second tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr	*tensr_sub(const t_tensr *a, const t_tensr *b, t_tensr *out);

/*
 ** Divides tensor a by tensor b element-wise (broadcasting supported).
 **
 ** @param a         Pointer to the numerator tensor.
 ** @param b         Pointer to the denominator tensor.
 ** @param out       Optional output tensor. If NULL, a new tensor is allocated.
 **
 ** @return          A pointer to the result tensor, or NULL on failure.
 */
t_tensr	*tensr_div(const t_tensr *a, const t_tensr *b, t_tensr *out);

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
t_tensr	*tensr_clamp(const t_tensr *t, double min, double max, t_tensr *out);

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
t_tensr	*tensr_sum(const t_tensr *t, const int n_axes, const size_t *axes);

/*
 ** Computes the maximum of elements along specified axes.
 **
 ** @param t         Pointer to the input tensor.
 ** @param n_axes    Number of axes to reduce.
 ** @param axes      Array of axis indices to reduce.
 **
 ** @return          A pointer to the reduced tensor, or NULL on failure.
 */
t_tensr	*tensr_max(const t_tensr *t, const int n_axes, const size_t *axes);

/*
 ** Computes the minimum of elements along specified axes.
 **
 ** @param t         Pointer to the input tensor.
 ** @param n_axes    Number of axes to reduce.
 ** @param axes      Array of axis indices to reduce.
 **
 ** @return          A pointer to the reduced tensor, or NULL on failure.
 */
t_tensr	*tensr_min(const t_tensr *t, const int n_axes, const size_t *axes);

/*
 ** Computes the mean of elements along specified axes.
 **
 ** @param t         Pointer to the input tensor.
 ** @param n_axes    Number of axes to reduce.
 ** @param axes      Array of axis indices to reduce.
 **
 ** @return          A pointer to the reduced tensor, or NULL on failure.
 */
t_tensr	*tensr_mean(const t_tensr *t, const int n_axes, const size_t *axes);

#endif
