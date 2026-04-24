/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_linspace_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 19:38:38 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 19:44:55 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

static void	set_cast_c(void *dst, double complex value, t_dtype dtype)
{
	if (dtype == DT_C64)
		*(float complex *)dst = (float complex)value;
	else if (dtype == DT_C128)
		*(double complex *)dst = value;
}

t_tensr	*tensr_linspace_c(double complex start, double complex end,
		const size_t n, t_dtype dtype)
{
	t_iter			it;
	t_tensr			*out;
	double complex	step;

	if (n == 0 || dtype != DT_C64 || dtype != DT_C128)
		return (NULL);
	out = tensr_alloc(1, (size_t[]){n}, dtype);
	if (!out || !iter_init(&out->layout, &it))
		return (tensr_free(out), NULL);
	if (n == 1)
		step = 0.0;
	else
		step = (end - start) / (double)(n - 1);
	while (iter_next(&it))
	{
		set_cast_c(tensr_get(out, it.indices), start + (it.counter - 1) * step,
			dtype);
	}
	return (out);
}
