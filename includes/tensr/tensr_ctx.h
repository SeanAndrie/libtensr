/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tensr_ctx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 22:30:24 by sgadinga          #+#    #+#             */
/*   Updated: 2026/05/14 01:59:04 by sgadinga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENSR_CTX_H
# define TENSR_CTX_H

# include <libft.h>
# include <harena.h>

typedef struct s_tensr_ctx
{
	t_harena		*graph;
	t_harena		*forward;
	t_harena		*scratch;
    t_bool          no_grad;
}					t_tensr_ctx;

extern _Thread_local t_tensr_ctx *ctx;

t_bool	tensr_ctx_set(const size_t graph_size, const size_t forward_size,
		const size_t scratch_size);

void    tensr_ctx_reset(void);
void    tensr_ctx_destroy(void);

void    *tensr_malloc(const size_t bytes);

#endif
