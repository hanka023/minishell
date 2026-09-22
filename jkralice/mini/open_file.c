/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 19:39:24 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 22:49:01 by jkralice         ###   ########.fr       */
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
		write(1, ERR_MSG, sizeof(ERR_MSG));
		write(1, "couldn't open file: ", 37);
		write(1, str, str_len(str));
		write(1, "!\n", 2);
	}
	return (fd);
}
