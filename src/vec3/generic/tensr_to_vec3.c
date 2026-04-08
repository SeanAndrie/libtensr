/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_to_vec3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 01:33:46 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/01 02:25:10 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libtensr.h>
#include <vec3/vec3.h>

t_vec3	tensr_to_vec3(t_tensr *t)
{
	t_vec3	vec;

	if (!t || t->size != 3)
		return ((t_vec3){0.0f, 0.0f, 0.0f});
	ft_memcpy(&vec, t->data, sizeof(t_vec3));
	return (vec);
}
