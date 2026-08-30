/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:35:13 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/30 16:55:47 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"
#include "../Lib42/str.h"

#include <unistd.h>

int	env(void *param, int in_fd, int out_fd)
{
	t_command_args	*args;
	char			**envp;
	size_t			i;

	args = (t_command_args *)param;
	(void)in_fd;
	envp = *args->envp;
	i = 0;
	while (envp[i])
	{
		write(out_fd, envp[i], str_len(envp[i]));
		write(out_fd, "\n", 1);
		i++;
	}
	return (0);
}
