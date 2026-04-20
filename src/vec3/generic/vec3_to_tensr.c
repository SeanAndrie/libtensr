/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_to_tensr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:41:17 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 22:10:22 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtensr.h>
#include <libvec3.h>

t_tensr	*vec3_to_tensr(t_vec3 v, const int ndim, const size_t *shape)
{
	int		i;
	size_t	size;
	t_array	array;

	if (!shape || ndim <= 0)
		return (NULL);
	size = 1;
	i = 0;
	while (i < ndim)
		size *= shape[i++];
	if (size != 3)
		return (NULL);
	array = arr_f32((float[]){v.x, v.y, v.z}, 3);
	return (tensr_from_arr(&array, ndim, shape, DT_F32));
}
