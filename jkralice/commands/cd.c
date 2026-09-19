/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:51:07 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/17 17:10:11 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"

#include <unistd.h>

int	cd(void *param)
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
