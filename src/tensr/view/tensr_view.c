/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:11:36 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/14 02:48:37 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr	*tensr_view(const t_tensr *t, void *data, const t_layout *l)
{
	int		i;
	t_tensr	*v;

	v = malloc(sizeof(t_tensr));
	if (!v)
		return (NULL);
	v->size = 1;
	v->data = data;
	v->owns_data = FALSE;
	if (t)
	{
		v->dtype = t->dtype;
		v->elemsize = t->elemsize;
	}
	i = 0;
	while (i < l->ndim)
		v->size *= l->shape[i++];
	if (!layout_alloc(l->ndim, &v->layout))
		return (free(v), NULL);
	if (!layout_copy(&v->layout, l))
		return (free(v), NULL);
	return (v);
}
