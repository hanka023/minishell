/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:47:17 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/29 16:21:47 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../Lib42/str.h"

#include <unistd.h>
#include <stdlib.h>

int	pwd(void *param, int in_fd, int out_fd)
{
	char	*dir;

	(void)param;
	(void)in_fd;
	dir = getcwd(NULL, 0);
	write(out_fd, dir, str_len(dir));
	free(dir);
	return (0);
}
