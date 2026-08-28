/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_add_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:08:40 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/24 12:12:16 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"
#include "limits.h"

int	pipeline_add_process(t_pipeline *ppl, char *path, char **argv, char **envp)
{
	t_ppl_link	*link;

	link = ppl_chain_add_back((t_ppl_chain *)ppl);
	*link = (t_ppl_link){
		.type = PPL_PROCESS,
		.data.process = (t_ppl_link_process){
		.path = path,
		.argv = argv,
		.envp = envp,
		._pid = 0
	}};
	return (1);
}
