/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lerp_ip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:57:03 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/02 13:23:27 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec3/vec3_linalg.h>

void	vec3_lerp_ip(t_vec3 *curr, t_vec3 target, const float t)
{
	if (!curr)
		return ;
	vec3_add_ip(curr, vec3_scale(vec3_sub(target, *curr), t));
}
