/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:33:28 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/29 16:21:34 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../memory.h"
#include "../Lib42/str.h"

#include <unistd.h>

void	echo(void *param, int in_fd, int out_fd)
{
	t_echo_args	*args;
	int			n;
	size_t		i;

	args = (t_echo_args *)param;
	(void)in_fd;
	n = 0;
	if (args->argc)
		n = (
			str_len(args->argv[0]) == 2 && !mem_compare(args->argv[0], "-n", 2)
			);
	i = n;
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
