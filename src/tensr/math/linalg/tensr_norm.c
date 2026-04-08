/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_norm.c                                       :::      :(        :+    */
/*                                                    +:+ +:       +#          */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#  +:     +#           */
/*                                                +#    +#    +#            */
/*   Created: 2026/03/06 02:32:04 by sgadinga          #+#   #+    #+#        */
/*   Updated: 2026/03/30 07:24:17 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/linalg.h>
#include <libft.h>

t_tensr	*tensr_norm(const t_tensr *t, bool keepdims, t_tensr *out)
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
