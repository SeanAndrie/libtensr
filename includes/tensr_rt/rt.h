/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_rt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:00:00 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/17 16:23:45 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_RT_H
# define TENSR_RT_H

# ifdef TENSR_SIMD
#  include <immintrin.h>
# endif

typedef struct s_tensr	t_tensr;

typedef struct s_vec3
{
	float				x;
	float				y;
	float				z;
}						t_vec3;

typedef struct s_ray
{
	struct s_vec3		orig;
	struct s_vec3		dir;
}						t_ray;

#endif
