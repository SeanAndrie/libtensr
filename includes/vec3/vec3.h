/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:18:58 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 21:19:11 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <libft.h>
# include <math.h>

typedef struct s_tensr	t_tensr;

typedef struct s_vec3
{
	float				x;
	float				y;
	float				z;
}						t_vec3;

typedef struct s_project
{
	struct s_vec3		perp;
	float				axial;
}						t_project;

t_vec3					tensr_to_vec3(t_tensr *t);
t_tensr					*vec3_to_tensr(t_vec3 v, const int ndim,
							const size_t *shape);
t_bool					vec3_equal_eps(t_vec3 a, t_vec3 b, const float eps);

#endif
