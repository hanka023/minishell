/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:32:34 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 23:15:48 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../Lib42/str.h"

void	*find_command(char *str)
{
	int	(*foo)(void *);

	if (str_eq(str, "echo"))
		foo = cmd_echo;
	else if (str_eq(str, "cd"))
		foo = cmd_cd;
	else if (str_eq(str, "pwd"))
		foo = cmd_pwd;
	else if (str_eq(str, "export"))
		foo = cmd_export;
	else if (str_eq(str, "unset"))
		foo = cmd_unset;
	else if (str_eq(str, "env"))
		foo = cmd_env;
	else if (str_eq(str, "exit"))
		foo = cmd_exit;
	else
		return (NULL);
	return (foo);
}
