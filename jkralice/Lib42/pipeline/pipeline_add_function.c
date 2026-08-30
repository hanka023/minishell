/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_add_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:08:40 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/30 19:11:25 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"

int	pipeline_add_function(t_pipeline *ppl,
	int (*foo)(void *, int, int), void *param)
{
	t_ppl_link	*link;

	link = ppl_chain_add_back((t_ppl_chain *)ppl);
	*link = (t_ppl_link){
		.type = PPL_FUNCTION,
		.data.function = (t_ppl_link_function){
		.foo = foo,
		.param = param,
		._pid = 0
	}};
	return (1);
}
