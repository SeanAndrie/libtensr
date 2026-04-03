/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_clamp_ip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:42:04 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/03 10:47:18 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_rt/rt_math.h>

void    vec3_clamp_ip(t_vec3 *v, const float min, const float max)
{
    v->x = fmaxf(min, fminf(v->x, max));
    v->y = fmaxf(min, fminf(v->y, max));
    v->z = fmaxf(min, fminf(v->z, max));
}
