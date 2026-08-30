/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/28 17:17:24 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <errno.h>
#include <string.h>

#include "minishell.h"

void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		signal(SIGINT, SIG_DFL);
		raise(SIGINT);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int		j;

	j = 0;
	while (1)
	{
		if (signal(SIGINT, sighandler) == SIG_ERR)
		{
			perror ("signal");
			return (1);
		}
		while (j < 10)
		{
			++j;
			sleep (2);
		}
	}
	return (0);
}
