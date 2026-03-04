/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:49:08 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/04 21:34:05 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_MATH_H
# define TENSR_MATH_H

typedef union u_result
{
    int         i;
    long long   l;
    float       f;
    double      d;
}               t_result;

typedef struct s_tensr t_tensr;

t_tensr     *tensr_add(const t_tensr *a, const t_tensr *b);
t_tensr     *tensr_mul(const t_tensr *a, const t_tensr *b);
t_tensr     *tensr_sub(const t_tensr *a, const t_tensr *b);
t_tensr     *tensr_div(const t_tensr *a, const t_tensr *b);

t_tensr		*tensr_sum(const t_tensr *t, const int n_axes,
						const size_t *axes);
t_tensr		*tensr_max(const t_tensr *t, const int n_axes,
					    const size_t *axes);
t_tensr		*tensr_min(const t_tensr *t, const int n_axes,
						const size_t *axes);


#endif
