/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:51:07 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/21 15:04:10 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"

#include <unistd.h>

int	cmd_cd(void *param)
{
	t_command_args	*args;
	char			*path;

	args = (t_command_args *)param;
	if (args->argc == 1)
		path = "~";
	else if (args->argc == 2)
		path = args->argv[1];
	else
		return (1);
	return (chdir(path) == -1);
}
