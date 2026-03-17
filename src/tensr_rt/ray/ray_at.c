/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:50:41 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/17 17:58:48 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_rt/rt.h>
#include <tensr_rt/rt_math.h>

t_vec3  ray_at(t_ray ray, float t)
{
    return (vec3_add(ray->orig, vec3_scale(ray->dir, t)));
}
