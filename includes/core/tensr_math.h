/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:49:08 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/08 20:40:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_MATH_H
# define TENSR_MATH_H

typedef struct s_tensr	t_tensr;

// Elementwise Operations
t_tensr                 *tensr_abs(const t_tensr *t);
t_tensr					*tensr_neg(const t_tensr *t);
t_tensr					*tensr_sqrt(const t_tensr *t);
t_tensr					*tensr_add(const t_tensr *a, const t_tensr *b);
t_tensr					*tensr_mul(const t_tensr *a, const t_tensr *b);
t_tensr					*tensr_sub(const t_tensr *a, const t_tensr *b);
t_tensr					*tensr_div(const t_tensr *a, const t_tensr *b);
t_tensr                 *tensr_clamp(const t_tensr *t, double min, double max);

// Reductions Operations
t_tensr					*tensr_sum(const t_tensr *t, const int n_axes,
							const size_t *axes);
t_tensr					*tensr_max(const t_tensr *t, const int n_axes,
							const size_t *axes);
t_tensr					*tensr_min(const t_tensr *t, const int n_axes,
							const size_t *axes);
t_tensr                 *tensr_mean(const t_tensr *t, const int n_axes,
                            const size_t *axes);

// Linear Algebra Operations
t_tensr                 *tensr_norm(const t_tensr *t);
t_tensr					*tensr_dot(const t_tensr *a, const t_tensr *b);
t_tensr					*tensr_cross(const t_tensr *a, const t_tensr *b);
t_tensr                 *tensr_matmul(const t_tensr *a, const t_tensr *b);

#endif
