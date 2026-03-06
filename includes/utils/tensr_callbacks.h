/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_callbacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:30:45 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/05 20:33:40 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_CALLBACKS
# define TENSR_CALLBACKS

typedef enum e_dtype t_dtype;
typedef struct s_tensr t_tensr;

void	add_func(void *a, void *b, void *out, t_dtype dtype);
void	sub_func(void *a, void *b, void *out, t_dtype dtype);
void	mul_func(void *a, void *b, void *out, t_dtype dtype);
void	div_func(void *a, void *b, void *out, t_dtype dtype);

#endif
