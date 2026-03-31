/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:00:00 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/04/01 02:42:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_RT_H
# define TENSR_RT_H

# ifdef TENSR_SIMD
#  include <immintrin.h>
# endif

# include <libft.h>
# include <stdbool.h>

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

#endif
