/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:17:52 by sgadinga          #+#    #+#             */
/*   Updated: 2026/02/17 17:12:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_bool	tensr_set(const t_tensr *t, void *data, const size_t *indices)
{
	void	*ptr;
	size_t	elem_offset;
	size_t	byte_offset;

	if (!t || !data || !indices)
		return (FALSE);
	elem_offset = tensr_offset(&t->layout, indices);
	if (elem_offset == (size_t)-1)
		return (FALSE);
	byte_offset = elem_offset * t->elemsize;
	ptr = (char *)t->data + byte_offset;
	ft_memcpy(ptr, data, t->elemsize);
	return (TRUE);
}
