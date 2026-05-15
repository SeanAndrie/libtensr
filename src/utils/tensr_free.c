/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:04:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/14 01:51:11 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

void	tensr_free(t_tensr *t)
{
	if (!t)
		return ;
	layout_free(&t->layout);
	if (t->data && t->owns_data && !t->arena_owned)
		free(t->data);
    if (!t->arena_owned)
	    free(t);
}
