/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_next.c                                        :::      ::::::::   */
/*                                                    :::      ::::::::   */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  #+#    #+#             */
/*                                                  #+#    #+#             */
/*   Created: 2026/02/02 18:45:30 by sgadinga          #+#   #+#+#          */
/*   Updated: 2026/04/09 02:00:00 by sgadinga         ###    ########       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

bool    iter_next(t_iter *it)
{
    int i;

    if (it->counter >= it->total)
        return (false);
    if (it->counter == 0)
    {
        it->counter++;
        return (true);
    }
    i = it->layout->ndim - 1;
    while (i >= 0)
    {
        it->indices[i]++;
        if (it->indices[i] < it->layout->shape[i])
            break;
        it->indices[i] = 0;
        i--;
    }
    it->counter++;
    return (true);
}
