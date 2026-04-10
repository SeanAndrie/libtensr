/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 20:55:22 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/10 20:55:24 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

void    layout_free(t_layout *l)
{
    if (!l)
        return ;
    ft_memset(l, 0, sizeof(t_layout));
    l->ndim = 0;
    l->shape = NULL;
    l->stride = NULL;
}
