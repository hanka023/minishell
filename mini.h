/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:53:43 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/27 15:39:16 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

#include "Lib42/pipeline.h"

typedef struct s_state
{
	char		**envp;
	t_arena		*arena;
	t_pipeline	*pipeline;
	int			exit_code;
}	t_state;

//	Sets up the minishell's state.
t_state	setup(size_t arena_size, size_t scratch_count, size_t scratch_size);

//	Cleans up state before exit.
void	cleanup(t_state state);

#endif
