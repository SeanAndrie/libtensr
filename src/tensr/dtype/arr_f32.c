/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_f32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 23:38:57 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 17:58:14 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_array	arr_f32(float *data, const size_t len)
{
	return ((t_array){.data = data, .len = len, .dtype = DT_F32});
}
