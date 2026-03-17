/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:59:45 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/17 18:00:29 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_rt/rt.h>
#include <tensr_rt/rt_math.h>

t_ray   ray_create(t_vec3 orig, t_vec3 dir)
{
    return ((t_ray){
        .orig = orig;
        .dir = dir;
    });
}
