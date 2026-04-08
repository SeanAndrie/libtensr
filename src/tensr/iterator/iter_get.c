/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_get.c                                         :::      ::::::::   */
/*                                                    :::      ::::::::   */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  #+#    #+#             */
/*                                                  #+#    #+#             */
/*   Created: 2026/04/09 02:00:00 by sgadinga         #+#   #+#+#          */
/*   Updated: 2026/04/09 02:00:00 by sgadinga         ###    ########       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

void	*iter_get(t_iter *it)
{
	if (it->contiguous)
		return (it->data_ptr + it->counter * it->tensor->elemsize);
	return (tensr_get(it->tensor, it->indices));
}