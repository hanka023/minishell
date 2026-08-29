/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:39:55 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/29 16:21:21 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"

int	export(void *param, int in_fd, int out_fd)
{
	t_export_args	*args;
	char			**tmp;

	(void)in_fd;
	(void)out_fd;
	args = (t_export_args *)param;
	tmp = map_add(*(args->envp), args->key, args->val);
	if (!tmp && !map_change(*(args->envp), args->key, args->val))
			return (1);
	*(args->envp) = tmp;
	return (0);
}
