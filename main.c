/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:53:10 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/23 20:37:21 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mini.h"
#include "jkralice/Lib42/lib42.h"

#include <signal.h>
#include <readline/readline.h>

int	g_signum = 0;

void	sigint_handler(int signum)
{
	g_signum = signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigquit_handler(int signum)
{
	g_signum = signum;
}

int	main(int argc, char **argv, char **envp)
{
	t_state	state;
	t_list	*tokens;

	(void)argc;
	(void)argv;
	rl_catch_signals = 0;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	state = setup(envp, gib(1), 2, mib(128));
	state.running = 1;
	while (state.running)
	{
		g_signum = 0;
		tokens = input(&state);
		if (tokens == (void *)1)
			break ;
		interpret(&state, tokens);
		free_list(tokens);
	}
	cleanup(state);
	return (0);
}
