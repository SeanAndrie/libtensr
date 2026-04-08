/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 03:09:27 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 01:22:43 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3/vec3_linalg.h>

t_project	vec3_project(t_vec3 v, t_vec3 axis)
{
	t_project	proj;
	t_vec3		u_hat;

	u_hat = vec3_normalize(axis);
	proj.axial = vec3_dot(v, u_hat);
	proj.perp = vec3_sub(v, vec3_scale(u_hat, proj.axial));
	return (proj);
}
