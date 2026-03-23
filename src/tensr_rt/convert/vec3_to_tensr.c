/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_tensr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:41:17 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/23 21:44:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <libtensr_rt.h>

t_tensr *vec3_to_tensr(const t_vec3 v)
{
    t_array arr;
    
    arr = arr_f32((float[]){v.x, v.y, v.z}, 3);
    return (tensr_from_arr(&arr, 1, (size_t[]){3}, DT_F32));
}

