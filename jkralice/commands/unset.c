/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:36:44 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/30 16:32:37 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"

void	separate_key_val(char *str, char **key_out, char **val_out);

int	unset(void *param, int in_fd, int out_fd)
{
	t_command_args	*args;
	char			**tmp;
	char			*key;
	char			*val;
	size_t			i;

	args = (t_command_args *)param;
	(void)in_fd;
	(void)out_fd;
	i = 1;
	while (i < (size_t)args->argc)
	{
		separate_key_val(args->argv[i], &key, &val);
		tmp = map_remove(*(args->envp), key);
		if (tmp)
			*(args->envp) = tmp;
		i++;
	}
	return (0);
}
