/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_clinspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 21:12:24 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 21:12:25 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

static void	set_cast_c(void *dst, double complex val, t_dtype dtype)
{
	if (dtype == DT_C64)
		*(float complex *)dst = (float complex)val;
	else if (dtype == DT_C128)
		*(double complex *)dst = val;
}

t_tensr	*tensr_clinspace(double complex start, double complex end,
		const size_t n, t_dtype dtype)
{
	t_iter			it;
	t_tensr			*out;
	double complex	step;

	if (n == 0 || (dtype != DT_C64 && dtype != DT_C128))
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
