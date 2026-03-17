/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:50:31 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/17 17:11:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr_core/core.h>

void	*tensr_get(const t_tensr *t, const size_t *indices)
{
	size_t	elem_offset;
	size_t	byte_offset;

	if (!t || !indices)
		return (NULL);
	elem_offset = tensr_offset(&t->layout, indices);
	if (elem_offset == (size_t)-1)
		return (NULL);
	byte_offset = elem_offset * t->elemsize;
	return ((char *)t->data + byte_offset);
}
