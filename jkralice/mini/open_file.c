/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:39:24 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/23 21:09:27 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_mini.h"
#include "../Lib42/str.h"

int	open_file(char *str, int flags)
{
	int	fd;

	fd = open(str, flags, 0666);
	if (fd == -1)
	{
		write(STDERR_FILENO, ERR_MSG, sizeof(ERR_MSG));
		write(STDERR_FILENO, "couldn't open file: ", 20);
		write(STDERR_FILENO, str, str_len(str));
		write(STDERR_FILENO, "!\n", 2);
	}
	return (fd);
}
