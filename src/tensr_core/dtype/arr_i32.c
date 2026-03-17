/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_i32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:32:43 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/02 14:48:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

t_array	arr_i32(int32_t *data, const size_t len)
{
	return ((t_array){.data = data, .len = len, .dtype = DT_I32});
}
