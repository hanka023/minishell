/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mini.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:37:46 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/23 21:47:04 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINI_H
# define _MINI_H

# include "../../mini.h"

//	Shell's heredoc function.
//	Returns the read end file descriptor of a pipe.
int		heredoc(char *del);

//	Opens a file and returns the file descriptor.
//	Prints a message on error.
int		open_file(char *str, int flags);

//	Internal variables of `interpret()`.
typedef struct s_interpret_variables
{
	t_arena_temp	temp;
	int				argc;
	char			**argv;
	t_list			*tokens;
	int				fd[2];
}	t_intvars;

//	Adds `str` to the argument list.
//	Assumes NULL to be an empty list.
//	Does not copy!
void	argv_add(t_intvars *var, char *str);

//	0 on success 1 on error.
int		interpret_handle_heredoc(t_intvars *var, t_list **list);
int		interpret_handle_redir_in(t_intvars *var, t_list **list);
int		interpret_handle_redir_out(t_intvars *var, t_list **list);
int		interpret_handle_redir_append(t_intvars *var, t_list **list);

//	0 on success 2 on error.
int		interpret_add_link(t_state *state, t_intvars *var);

#endif
