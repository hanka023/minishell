/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:36:44 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/29 16:24:51 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"

int	unset(void *param, int in_fd, int out_fd)
{
	t_unset_args	*args;
	char			**tmp;

	args = (t_unset_args *)param;
	(void)in_fd;
	(void)out_fd;
	*(args->envp) = map_remove(*(args->envp), args->key);
	return (0);
}
