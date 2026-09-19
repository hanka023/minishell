/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_create_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:08:40 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/17 15:49:57 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipeline.h"
#include "limits.h"

t_ppl_link	ppl_create_process(char *path, char **argv, char **envp, int fd[2])
{
	t_ppl_link	link;

	{
		link.type = PPL_TYPE_PROCESS;
		link.data.process.path = path;
		link.data.process.argv = argv;
		link.data.process.envp = envp;
		link.fd[0] = fd[0];
		link.fd[1] = fd[1];
		link._pid = 0;
	}
	return (link);
}
