/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _heredoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:33:51 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/31 18:13:07 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../Lib42/memory.h"
#include "../Lib42/str.h"
#include "../../hskalov/gnl/get_next_line.h"

#include <unistd.h>

int	_heredoc(void *param, int in_fd, int out_fd)
{
	t_heredoc_args	*args;
	size_t			del_len;
	size_t			line_len;
	char			*line;
	char			*found;

	args = (t_heredoc_args *)param;
	(void)in_fd;
	del_len = str_len(args->delimiter);
	line = get_next_line(0);
	while (line)
	{
		line_len = str_len(line);
		found = mem_search(line, line_len, args->delimiter, del_len);
		if (found)
		{
			write(out_fd, line, (size_t)(found - line));
			break ;
		}
		write(1, line, line_len);
		line = get_next_line(0);
	}
	return (0);
}
