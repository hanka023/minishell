/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:53:43 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/29 16:59:20 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "jkralice/Lib42/pipeline.h"
# include "hskalov/minishell.h"

# ifndef PROMPT
#  define PROMPT "\e[032m[ mini ] > \e[0m"
# endif

typedef struct s_state
{
	char		**envp;
	t_arena		*arena;
	int			exit_code;
}	t_state;

//	Sets up the minishell's state.
t_state	setup(size_t arena_size, size_t scratch_count, size_t scratch_size);

//	Cleans up state before exit.
void	cleanup(t_state state);

//	Gather and parse input.
t_list	*input(t_state *state);

//	Interprets and runs the input.
void	interpret(t_state *state, t_list *list);

#endif
