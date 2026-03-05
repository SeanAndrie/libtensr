/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_debug.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:10:55 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/02 16:18:24 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_DEBUG_H
# define TENSR_DEBUG_H

#include <stdio.h>

// IMPORTANT: Remove debug header and directory when submitting!

typedef struct s_tensr t_tensr;

void    tensr_metadata(const char *name, t_tensr *t);
void    tensr_print(const t_tensr *t);

#endif
