/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:42:50 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/17 17:21:51 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_rt/rt_math.h>

t_vec3	vec3_normalize(t_vec3 v)
{
	float	norm;

	norm = sqrt(vec3_dot(v, v));
	if (norm == 0.0f)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3) {
		.x = v.x / norm,
		.y = v.y / norm,
		.z = v.z / norm
	});
}
