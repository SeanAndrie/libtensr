/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_from_arr.c                                    :,      ::::::::   */
/*                                                    :,      :,    :,+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +:   +:  +:+:         */
/*                                                +:+#+#++:++#++            */
/*   Created: 2026/01/26 22:33:23 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/19 21:38:23 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr	*tensr_from_arr(t_array *arr, const int ndim, const size_t *shape,
		t_dtype dtype)
{
	t_tensr	*t;

	if (!arr || !arr->data || ndim <= 0 || !shape)
		return (NULL);
	if (arr->dtype != dtype)
		return (NULL);
	t = tensr_alloc(ndim, shape, dtype);
	if (!t)
		return (NULL);
	ft_memcpy(t->data, arr->data, t->elemsize * t->size);
	return (t);
}