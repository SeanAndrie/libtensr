/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lerp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:52:27 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 13:21:49 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3/vec3_linalg.h>

t_vec3	vec3_lerp(t_vec3 curr, t_vec3 target, const float t)
{
	return (vec3_add(curr, vec3_scale(vec3_sub(target, curr), t)));
}
