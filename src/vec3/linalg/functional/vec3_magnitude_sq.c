/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_magnitude_sq.c                                   :::      ::::::::   */
/*                                                    +:+ +:+         +:     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:++:+         +:      */
/*                                                +:    +#     :+#         */
/*   Created: 2026/03/17 17:40:00 by sgadinga          #+#   #+        #+#    */
/*   Updated: 2026/03/17 17:40:00 by sgadinga         ###    ########.ag      */
/*                                                                            */
/* ************************************************************************** */

#include <vec3/vec3_linalg.h>

float	vec3_magnitude_sq(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}
