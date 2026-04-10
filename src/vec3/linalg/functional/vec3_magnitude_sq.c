/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_magnitude_sq.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:51:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 21:51:25 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3/vec3_linalg.h>

float	vec3_magnitude_sq(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}
