/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:53:10 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/23 19:00:11 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mini.h"
#include "jkralice/Lib42/lib42.h"

int	main(int argc, char **argv, char **envp)
{
	t_state	state;
	t_list	*tokens;

	(void)argc;
	(void)argv;
	state = setup(envp, gib(1), 2, mib(128));
	state.running = 1;
	while (state.running)
	{
		tokens = input(&state);
		interpret(&state, tokens);
	}
	cleanup(state);
	return (0);
}
