/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:12:50 by sgadinga          #+#    #+#             */
/*   Updated: 2025/11/13 15:22:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

typedef struct s_tensr t_tensr;

void    tensr_data(t_tensr *t);
void    tensr_info(t_tensr *t, const char *name);

#endif

