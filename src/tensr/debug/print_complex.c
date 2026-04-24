/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:36:49 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/24 18:43:28 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <complex.h>
#include <tensr/tensr.h>
#include <tensr/tensr_debug.h>

void	print_c64(const char *ptr)
{
	float complex	v;
	float			re;
	float			im;

	v = *(const float complex *)ptr;
	re = crealf(v);
	im = cimagf(v);
	if (im < 0)
		ft_printf("%f-%fi", (double)re, (double)-im);
	else
		ft_printf("%f+%fi", (double)re, (double)im);
}

void	print_c128(const char *ptr)
{
	double complex	v;
	double			re;
	double			im;

	v = *(const double complex *)ptr;
	re = creal(v);
	im = cimag(v);
	if (im < 0)
		ft_printf("%f-%fi", re, -im);
	else
		ft_printf("%f+%fi", re, im);
}
