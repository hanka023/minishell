/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:51:07 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/30 16:26:17 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"

#include <unistd.h>

int	cd(void *param, int in_fd, int out_fd)
{
	t_command_args	*args;
	char			*path;

	args = (t_command_args *)param;
	(void)in_fd;
	(void)out_fd;
	if (args->argc == 1)
		path = "~";
	else if (args->argc == 2)
		path = args->argv[0];
	else
		return (1);
	return (chdir(path) == -1);
}

