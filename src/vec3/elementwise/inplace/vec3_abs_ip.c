/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_abs_ip.c                                        :::      ::::::::   */
/*                                                    +:+ +:+         +:     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +:    +#     :+#         */
/*   Created: 2026/03/17 17:40:00 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/17 17:40:00 by sgadinga         ###    ########.ag      */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <vec3/vec3_elem.h>

void	vec3_abs_ip(t_vec3 *v)
{
	v->x = fabsf(v->x);
	v->y = fabsf(v->y);
	v->z = fabsf(v->z);
}
