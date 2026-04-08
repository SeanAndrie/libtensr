/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:42:50 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 00:20:28 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3/rt_math.h>

t_vec3	vec3_normalize(t_vec3 v)
{
	float	mag;

	mag = vec3_magnitude(v);
	if (mag == 0.0f)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3) {
		.x = v.x / mag,
		.y = v.y / mag,
		.z = v.z / mag 
	});
}
