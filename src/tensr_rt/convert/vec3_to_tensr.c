/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_tensr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:41:17 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/24 00:01:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <libtensr_rt.h>

t_tensr *vec3_to_tensr(const t_vec3 v, bool row)
{
    t_array arr;
    float   data[3];
    size_t  shape[2];
    
    data[0] = v.x;
    data[1] = v.y;
    data[2] = v.z;
    if (row)
    {
        shape[0] = 1;
        shape[1] = 3;
    }
    else
    {
        shape[0] = 3;
        shape[1] = 1;
    }
    arr = arr_f32(data, 3);
    return (tensr_from_arr(&arr, 2, shape, DT_F32));
}

