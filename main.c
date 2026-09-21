/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:53:10 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/21 16:38:38 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	jkralice
#include "mini.h"
#include "jkralice/Lib42/lib42.h"

//	stdlib
#include <unistd.h>

//	readline
#include <readline/readline.h>
#include <readline/history.h>


int	main(void)
{
	t_state	state;
	char	*line;

	state = setup(gib(1), 2, mib(128));
	while (1)
	{
		line = readline(PROMPT);
        if (!line) // NULL = EOF / Ctrl+D
            break ;
		if (line[0] == '\0')
        {
            free(line);
            continue ;
        }
		add_history(line);

		state.list = input(&state, line);
		interpret(&state);
		free_list(state.list);
	}
	rl_clear_history();
	cleanup(state);
	return (0);
}
