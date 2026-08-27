/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:33:28 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/03 17:55:05 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../memory.h"

#include <unistd.h>

size_t	str_len(char *str);

void	echo(int argc, char **argv)
{
	int		n;
	size_t	i;

	n = 0;
	if (argc)
		n = (str_len(argv[0]) == 2 && !mem_compare(argv[0], "-n", 2));
	i = n;
	while (i < (size_t)argc)
	{
		write(1, argv[i], str_len(argv[i]));
		i++;
		if (i < (size_t)argc)
			write(1, " ", 1);
	}
	if (!n)
		write(1, "\n", 1);
}
