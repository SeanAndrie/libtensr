/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_u8.c                                            :::      ::::::::   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+-# ++#           */
/*   Created: 2026/03/13 by sgadinga                          #+#    #+#     */
/*   Updated: 2026/03/13 by sgadinga                         ###   ########.fr */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_array	arr_u8(uint8_t *data, const size_t len)
{
	return ((t_array){.data = data, .len = len, .dtype = DT_U8});
}
