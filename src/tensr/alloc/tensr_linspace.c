/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_linspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:12:43 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/10 14:26:01 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>
#include <tensr/debug.h>

static void	set_cast(void *dst, double value, t_dtype dtype)
{
    if (dtype == DT_U8)
        *(uint8_t *)dst = (uint8_t)value;
    else if (dtype == DT_I32)
		*(int32_t *)dst = (int32_t)value;
	else if (dtype == DT_I64)
		*(int64_t *)dst = (int64_t)value;
	else if (dtype == DT_F32)
		*(float *)dst = (float)value;
	else if (dtype == DT_F64)
		*(double *)dst = value;
}

t_tensr	*tensr_linspace(double start, double end, const size_t n, t_dtype dtype)
{
	t_iter	it;
	t_tensr	*out;
	double	step;

	if (n == 0)
		return (NULL);
	out = tensr_alloc(1, (size_t[]){n}, dtype);
	if (!out || !iter_init(&out->layout, &it))
		return (tensr_free(out), NULL);
	if (n == 1)
		step = 0.0;
	else
		step = ((end - start) / (double)(n - 1));
	while (iter_next(&it))
		set_cast(tensr_get(out, it.indices), start + (it.counter - 1) * step,
			dtype);
	return (out);
}
