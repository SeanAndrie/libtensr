/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:06:37 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 21:06:39 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr	*tensr_complex(double complex n, t_dtype dtype)
{
	t_tensr	*out;

	if (dtype != DT_C64 && dtype != DT_C128)
		return (NULL);
	out = tensr_alloc(0, NULL, dtype);
	if (!out)
		return (NULL);
	if (dtype == DT_C64)
		*(float complex *)out->data = n;
	else if (dtype == DT_C128)
		*(double complex *)out->data = n;
	else
		return (NULL);
	return (out);
}
