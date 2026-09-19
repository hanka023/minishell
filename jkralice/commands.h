/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:27:50 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/17 17:11:04 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

typedef struct s_command_args
{
	int		argc;
	char	**argv;
	char	***envp;
}	t_command_args;

int		echo(void *param);
int		cd(void *param);
int		pwd(void *param);
int		export(void *param);
int		unset(void *param);
int		env(void *param);

typedef struct s_heredoc_args
{
	char	*delimiter;
}	t_heredoc_args;

int		_heredoc(void *param);

#endif
