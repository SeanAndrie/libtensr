/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_abs.c                                          :::      ::::::::   */
/*                                                    +:+ +:+         +:     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +:    +#     :+#         */
/*   Created: 2026/03/17 17:40:00 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/17 17:40:00 by sgadinga         ###    ########.ag      */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <vec3/rt_math.h>

t_vec3	vec3_abs(t_vec3 v)
{
	return ((t_vec3){
		.x = fabsf(v.x),
		.y = fabsf(v.y),
		.z = fabsf(v.z)
	});
}
