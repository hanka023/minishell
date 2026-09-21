/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:33:28 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/21 15:14:05 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../Lib42/memory.h"
#include "../Lib42/str.h"

#include <unistd.h>

int	cmd_echo(void *param)
{
	t_command_args	*args;
	int				n;
	size_t			i;

	args = (t_command_args *)param;
	n = 0;
	if (args->argc > 1)
		n = (
			str_len(args->argv[1]) == 2 && !mem_compare(args->argv[1], "-n", 2)
			);
	i = 1 + n;
	while (i < (size_t)args->argc)
	{
		write(STDOUT_FILENO, args->argv[i], str_len(args->argv[i]));
		i++;
		if (i < (size_t)args->argc)
			write(STDOUT_FILENO, " ", 1);
	}
	if (!n)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
