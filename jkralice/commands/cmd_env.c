/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:35:13 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/21 15:04:15 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"
#include "../Lib42/str.h"

#include <unistd.h>

int	cmd_env(void *param)
{
	t_command_args	*args;
	char			**envp;
	size_t			i;

	args = (t_command_args *)param;
	envp = *args->envp;
	i = 0;
	while (envp[i])
	{
		write(STDOUT_FILENO, envp[i], str_len(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
