/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:31:53 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/23 18:59:50 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_mini.h"

int	interpret_handle_heredoc(t_intvars *var, t_list **list)
{
	int	fd;

	*list = (*list)->next;
	fd = heredoc((*list)->str);
	if (fd == -1)
	{
		write(STDERR_FILENO, ERR_MSG, sizeof(ERR_MSG));
		write(STDERR_FILENO, "heredoc failed!\n", 33);
		return (0);
	}
	else
	{
		var->fd[0] = fd;
		return (1);
	}
}

int	interpret_handle_redir_in(t_intvars *var, t_list **list)
{
	int	fd;

	*list = (*list)->next;
	fd = open_file((*list)->str, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		var->fd[0] = fd;
		return (1);
	}
}

int	interpret_handle_redir_out(t_intvars *var, t_list **list)
{
	int	fd;

	*list = (*list)->next;
	fd = open_file((*list)->str, O_CREAT | O_TRUNC | O_WRONLY);
	if (fd == -1)
		return (0);
	else
	{
		var->fd[1] = fd;
		return (1);
	}
}

int	interpret_handle_redir_append(t_intvars *var, t_list **list)
{
	int	fd;

	*list = (*list)->next;
	fd = open_file((*list)->str, O_APPEND | O_WRONLY);
	if (fd == -1)
		return (0);
	else
	{
		var->fd[1] = fd;
		return (1);
	}
}
