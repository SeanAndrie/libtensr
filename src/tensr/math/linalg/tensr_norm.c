/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:32:52 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 21:32:54 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tensr/tensr.h>
#include <tensr/tensr_math.h>

t_tensr	*tensr_norm(const t_tensr *t, t_bool keepdims, t_tensr *out)
{
	t_tensr	*dot;
	size_t	axis;

	if (!t)
		return (NULL);
	axis = (size_t)t->layout.ndim - 1;
	dot = tensr_inner(t, t, 1, &axis);
	if (!dot)
		return (NULL);
	out = tensr_sqrt(dot, out);
	tensr_free(dot);
	if (!out)
		return (NULL);
	if (keepdims && t->layout.ndim > 2)
	{
		if (!tensr_expand_dims(out, t->layout.ndim - 1))
		{
			tensr_free(out);
			return (NULL);
		}
	}
	return (out);
}
