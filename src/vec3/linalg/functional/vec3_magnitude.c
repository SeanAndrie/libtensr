/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_magnitude.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:23:46 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 00:20:44 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <vec3/vec3_linalg.h>

float	vec3_magnitude(t_vec3 v)
{
	return (sqrtf(vec3_dot(v, v)));
}
