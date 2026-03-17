/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_i64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:31:38 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/02 14:47:59 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

t_array	arr_i64(int64_t *data, const size_t len)
{
	return ((t_array){.data = data, .len = len, .dtype = DT_I64});
}
