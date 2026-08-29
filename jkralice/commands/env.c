/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:35:13 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/29 16:21:13 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"

int	env(void *param, int in_fd, int out_fd)
{
	t_env_args	*args;
	size_t	i;

	args = (t_env_args *)param;
	(void)in_fd;
	i = 0;
	while (args->envp[i])
	{
		write(out_fd, args->envp[i], str_len(args->envp[i]));
		write(out_fd, "\n", 1);
		i++;
	}
	return (0);
}
