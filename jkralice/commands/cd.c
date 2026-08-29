/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:51:07 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/29 16:21:45 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"

#include <unistd.h>

int	cd(void *param, int in_fd, int out_fd)
{
	t_cd_args	*args;

	args = (t_cd_args *)param;
	(void)in_fd;
	(void)out_fd;
	return (!chdir(args->path));
}

