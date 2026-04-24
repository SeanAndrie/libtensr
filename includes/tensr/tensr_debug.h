/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_debug.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:31:38 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/25 01:04:38 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_DEBUG_H
# define TENSR_DEBUG_H

typedef struct s_tensr	t_tensr;

void					print_c64(const char *ptr);
void					print_c128(const char *ptr);

/*
 ** Prints information about a tensor (shape, stride, dtype and data pointer).
 **
 ** @param name      Optional name to display with the tensor info (can be NULL).
 ** @param t        Pointer to the tensor to inspect.
 */
void					tensr_info(const char *name, t_tensr *t);

/*
 ** Prints the tensor's data to stdout in a readable format.
 **
 ** @param t        Pointer to the tensor to print.
 */
void					tensr_print(t_tensr *t);

#endif
