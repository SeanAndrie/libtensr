/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_ctx_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:43:10 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/13 20:01:58 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tensr/tensr.h>

t_bool	tensr_ctx_set(const size_t graph_size, const size_t forward_size,
		const size_t scratch_size)
{
	ctx = malloc(sizeof(t_tensr_ctx));
	if (!ctx)
		return (FALSE);
	ctx->graph = harena_create(graph_size);
	if (!ctx->graph)
		return (free(ctx), FALSE);
	ctx->forward = harena_create(forward_size);
	if (!ctx->forward)
	{
		harena_free(ctx->graph);
		return (free(ctx), FALSE);
	}
	ctx->scratch = harena_create(scratch_size);
	if (!ctx->scratch)
	{
		harena_free(ctx->forward);
		harena_free(ctx->graph);
		return (free(ctx), FALSE);
	}
    ft_printf("Context has been set!\n");
	return (TRUE);
}
