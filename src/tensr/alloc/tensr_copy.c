/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:42:50 by sgadinga          #+#    #+#             */
/*   Updated: 2026/03/09 15:35:53 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_tensr *tensr_copy(const t_tensr *t)
{
    t_tensr *cpy;

    if (!t)
        return (NULL);
    cpy = tensr_alloc(t->layout.ndim, t->layout.shape, t->dtype);
    if (!cpy)
        return (NULL);
    ft_memcpy(cpy->data, t->data, (t->size * t->elemsize));
    return (cpy);
}
