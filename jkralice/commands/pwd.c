/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:47:17 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/21 14:52:26 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"

#include <unistd.h>
#include <stdlib.h>

size_t	str_len(char *str);

int	pwd(void)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (!dir)
		return (0);
	write(1, dir, str_len(dir));
	free(dir);
	return (1);
}
