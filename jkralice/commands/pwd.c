/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:47:17 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/18 10:39:47 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../Lib42/str.h"

#include <unistd.h>
#include <stdlib.h>

int	pwd(void *param)
{
	char	*dir;

	(void)param;
	dir = getcwd(NULL, 0);
	write(STDOUT_FILENO, dir, str_len(dir));
	write(STDOUT_FILENO, "\n", 1);
	free(dir);
	return (0);
}
