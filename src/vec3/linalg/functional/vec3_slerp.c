/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_slerp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 11:48:25 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 12:04:22 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3/vec3_linalg.h>

t_vec3	vec3_slerp(t_vec3 curr, t_vec3 target, const float t)
{
	float	dot;
	t_vec3	perp;
	float	angle;

    dot = fmaxf(-1.0f, fminf(vec3_dot(curr, target), 1.0f));
	if (dot > 0.9999f)
		return (vec3_normalize(vec3_lerp(curr, target, t)));
	perp = vec3_normalize(vec3_sub(target, vec3_scale(curr, dot)));
	angle = acosf(dot) * t;
	return (vec3_add(vec3_scale(curr, cosf(angle)), vec3_scale(perp,
				sinf(angle))));
}
