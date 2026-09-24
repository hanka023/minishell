/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:53:43 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 23:04:19 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "jkralice/Lib42/pipeline.h"
# include "hskalov/minishell.h"

# ifndef PROMPT
#  define PROMPT "\e[032m[ mini ] > \e[0m"
# endif

# ifndef ERR_MSG
#  define ERR_MSG "\e[031m[!]\e[0m mini error: "
# endif

//	Global state of minishell.
typedef struct s_state
{
	t_arena		*arena;		//	Global arena.
	char		**envp;		//	Environment variables.
	t_ppl		*ppl;		//	Shell's pipeline. (cached for memory reuse)
	int			exit_code;	//	Last processe's exit code.
	int			running;	//	Self explanatory.
}	t_state;

//	Sets up minishell's state.
t_state	setup(
			char **envp,
			size_t arena_size,
			size_t scratch_count,
			size_t scratch_size
			);

//	Gather and parse input.
t_list	*input(t_state *state);

//	Interprets and runs the input.
void	interpret(t_state *state, t_list *tokens);

//	Cleans up state before exit.
void	cleanup(t_state state);

#endif
