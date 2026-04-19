/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_normalize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:06:52 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/31 00:17:35 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/tensr_math.h>

t_tensr	*tensr_normalize(const t_tensr *t, t_tensr *out)
{
	t_tensr	*res;
	t_tensr	*norm;

	if (!t)
		return (NULL);
	norm = tensr_norm(t, true, NULL);
	if (!norm)
		return (NULL);
	res = tensr_div(t, norm, out);
	tensr_free(norm);
	if (!res)
		return (NULL);
	return (res);
}
