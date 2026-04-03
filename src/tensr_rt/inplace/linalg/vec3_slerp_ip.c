/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_slerp_ip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:09:51 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 12:12:36 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_rt/rt_math.h>

void   vec3_slerp_ip(t_vec3 *curr, t_vec3 target, const float t)
{
    float   dot;
    t_vec3  perp;
    float   angle;

    dot = fmaxf(-1.0f, fminf(vec3_dot(*curr, target), 1.0f));
    if (dot > 0.9999f)
    {
        vec3_lerp_ip(curr, target, t);
        vec3_normalize_ip(curr);
        return ;
    }
    perp = vec3_normalize(vec3_sub(target, vec3_scale(*curr, dot)));
    angle = acosf(dot) * t;
    vec3_scale_ip(curr, cosf(angle));
    vec3_add_ip(curr, vec3_scale(perp, sinf(angle)));
}
