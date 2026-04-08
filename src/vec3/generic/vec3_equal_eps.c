/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_equal_eps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:37:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 10:35:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <vec3/vec3.h>

bool	vec3_equal_eps(t_vec3 a, t_vec3 b, const float eps)
{
	return ((fabsf(a.x - b.x) < eps) && (fabsf(a.y - b.y) < eps) && (fabsf(a.z
				- b.z) < eps));
}
