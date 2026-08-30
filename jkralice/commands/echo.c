/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:33:28 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/30 16:30:33 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../Lib42/memory.h"
#include "../Lib42/str.h"

#include <unistd.h>

int	echo(void *param, int in_fd, int out_fd)
{
	t_command_args	*args;
	int				n;
	size_t			i;

	args = (t_command_args *)param;
	(void)in_fd;
	n = 0;
	if (args->argc > 1)
		n = (
			str_len(args->argv[1]) == 2 && !mem_compare(args->argv[1], "-n", 2)
			);
	i = 1 + n;
	while (i < (size_t)args->argc)
	{
		write(out_fd, args->argv[i], str_len(args->argv[i]));
		i++;
		if (i < (size_t)args->argc)
			write(out_fd, " ", 1);
	}
	if (!n)
		write(out_fd, "\n", 1);
	return (0);
}
