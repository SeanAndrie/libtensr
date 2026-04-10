/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_elem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:19:35 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 21:20:00 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_ELEM_H
# define VEC3_ELEM_H

# include <vec3/vec3.h>

t_vec3	vec3_add(t_vec3 a, t_vec3 b);
void	vec3_add_ip(t_vec3 *a, t_vec3 b);

t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
void	vec3_sub_ip(t_vec3 *a, t_vec3 b);

t_vec3	vec3_mul(t_vec3 a, t_vec3 b);
void	vec3_mul_ip(t_vec3 *a, t_vec3 b);

t_vec3	vec3_div(t_vec3 a, t_vec3 b);
void	vec3_div_ip(t_vec3 *a, t_vec3 b);

t_vec3	vec3_neg(t_vec3 v);
void	vec3_neg_ip(t_vec3 *v);

t_vec3	vec3_abs(t_vec3 v);
void	vec3_abs_ip(t_vec3 *v);

#endif
