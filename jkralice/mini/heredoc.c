/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:31:03 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 23:47:00 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_mini.h"
#include "../Lib42/str.h"
#include "../Lib42/memory.h"
#include "../../hskalov/gnl/get_next_line.h"
#include <unistd.h>

static inline
char	*get_line(void)
{
	char	*out;

	write(1, "> ", 2);
	out = get_next_line(0);
	return (out);
}

int	heredoc(char *del)
{
	int		pipe_fd[2];
	size_t	del_len;
	char	*line;
	char	*found;

	if (pipe(pipe_fd) == -1)
		return (-1);
	del_len = str_len(del);
	line = get_line();
	while (line)
	{
		found = mem_search(line, str_len(line), del, del_len);
		if (found)
		{
			write(pipe_fd[1], line, (size_t)(found - line));
			break ;
		}
		write(pipe_fd[1], line, str_len(line));
		free(line);
		line = get_line();
	}
	free(line);
	close(pipe_fd[1]);
	return (pipe_fd[0]);
}
