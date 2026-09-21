/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:27:50 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/21 15:21:40 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../mini.h"

typedef struct s_command_args
{
	int		argc;
	char	**argv;
	char	***envp;
}	t_command_args;

int		cmd_echo(void *param);
int		cmd_cd(void *param);
int		cmd_pwd(void *param);
int		cmd_export(void *param);
int		cmd_unset(void *param);
int		cmd_env(void *param);

typedef struct s_exit_args
{
	int		argc;
	char	**argv;
	t_state	*state;
}	t_exit_args;

int		cmd_exit(void *param);

#endif
