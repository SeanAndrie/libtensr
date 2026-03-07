/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_callbacks.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:30:45 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/07 02:33:26 by sgadinga         ###   ########.fr       */
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

void    sum_init(void *acc, t_dtype dtype);
void    max_init(void *acc, t_dtype dtype);
void    min_init(void *acc, t_dtype dtype);

void	sum_apply(void *acc, const void *value, t_dtype dtype);
void	max_apply(void *acc, const void *value, t_dtype dtype);
void	min_apply(void *acc, const void *value, t_dtype dtype);

#endif
