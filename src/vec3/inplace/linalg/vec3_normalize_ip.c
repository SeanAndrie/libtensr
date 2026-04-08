/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize_ip.c                                :::      ::::::::   */
/*                                                    +:+ +:+         +:     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +:    +#     :+#         */
/*   Created: 2026/03/17 17:29:02 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/17 17:29:02 by sgadinga         ###    ########.ag      */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <vec3/rt_math.h>

void	vec3_normalize_ip(t_vec3 *v)
{
	float	mag;

	mag = vec3_magnitude(*v);
	if (mag == 0.0f)
		return ;
	v->x /= mag;
	v->y /= mag;
	v->z /= mag;
}
