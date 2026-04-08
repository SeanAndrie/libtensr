/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_clamp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:35:25 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 10:47:08 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <vec3/rt_math.h>

t_vec3  vec3_clamp(t_vec3 v, const float min, const float max)
{
    return ((t_vec3){
        .x = fmaxf(min, fminf(v.x, max)),
        .y = fmaxf(min, fminf(v.y, max)),
        .z = fmaxf(min, fminf(v.z, max))
    });
}
