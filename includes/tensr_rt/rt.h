/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:00:00 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/26 12:10:36 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_RT_H
# define TENSR_RT_H

# ifdef TENSR_SIMD
#  include <immintrin.h>
# endif

# include <stdbool.h>

typedef struct s_tensr t_tensr;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}			t_vec3;

t_tensr		*vec3_to_tensr(const t_vec3 v, bool row);

#endif
