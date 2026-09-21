/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:39:55 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/21 15:04:19 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"

void	separate_key_val(char *str, char **key_out, char **val_out);

int	cmd_export(void *param)
{
	t_command_args	*args;
	char			**tmp;
	char			*key;
	char			*val;
	size_t			i;

	args = (t_command_args *)param;
	i = 1;
	while (i < (size_t)args->argc)
	{
		separate_key_val(args->argv[i], &key, &val);
		tmp = map_add(*(args->envp), key, val);
		if (!tmp && !map_change(*(args->envp), key, val))
			tmp = *(args->envp);
		*(args->envp) = tmp;
		i++;
	}
	return (0);
}
