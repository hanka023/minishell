/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:39:55 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/24 13:20:55 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../map.h"
#include "../Lib42/str.h"

void	separate_key_val(char *str, char **key_out, char **val_out);


static
int	validate_identifier(char *id)
{
	size_t	i;
	size_t	len;

	if ((id[0] < 'A' || 'Z' < id[0])
		&& (id[0] < 'a' || 'z' < id[0])
		&& id[0] != '_')
		return (0);
	i = 1;
	len = str_len(id);
	while (i < len)
	{
		if ((id[i] < 'A' || 'Z' < id[i])
			&& (id[i] < 'a' || 'z' < id[i])
			&& (id[i] < '0' || '9' < id[i])
			&& id[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

// int	cmd_export(void *param)
// {
// 	t_command_args	*args;
// 	char			**tmp;
// 	char			*key;
// 	char			*val;
// 	size_t			i;

// 	args = (t_command_args *)param;
// 	i = 1;
// 	while (i < (size_t)args->argc)
// 	{
// 		separate_key_val(args->argv[i], &key, &val);
// 		if ((key && !validate_identifier(key)) || (val && !validate_identifier(val)))
// 			return (1);
// 		tmp = map_add(*(args->envp), key, val);
// 		if (!tmp)
// 			map_change(*(args->envp), key, val);
// 		else
// 			*(args->envp) = tmp;
// 		i++;
// 	}
// 	return (0);
// }


int	cmd_export(void *param)
{
	t_command_args	*args;
	char			**tmp;
	char			*key;
	char			*val;
	size_t			i;
	int				exit_status;

	exit_status = 0;
	args = (t_command_args *)param;
	i = 1;
	while (i < (size_t)args->argc)
	{
		separate_key_val(args->argv[i], &key, &val);
//		if ((key && !validate_identifier(key)) || (val && !validate_identifier(val)))
		if ((! key || !validate_identifier(key)))
		{
			write(STDERR_FILENO, "minishell: export: `", 20);
   			write(STDERR_FILENO, args->argv[i], str_len(args->argv[i]));
    		write(STDERR_FILENO, "': not a valid identifier\n", 26);
			exit_status = 1; 
		}
		else
		{
			tmp = map_add(*(args->envp), key, val);
			if (!tmp)
				map_change(*(args->envp), key, val);
			else
				*(args->envp) = tmp;
		}
		i++;
	}
	return (exit_status);
}