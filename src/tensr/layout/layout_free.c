/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_free.c                                      :::      ::::::::   */
/*                                                    :::      ::::      */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  :::      ::::       */
/*                                                :::      ::::       */
/*   Created: 2026/01/31 23:59:32 by sgadinga          #+#    #+#             */
/*   Updated: 2026/04/08 23:30:00 by sgadinga         ###   ########.fr       */
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
