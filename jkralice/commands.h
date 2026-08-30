/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:27:50 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/30 16:26:02 by jkralice         ###   ########.fr       */
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

int		echo(void *param, int in_fd, int out_fd);
int		cd(void *param, int in_fd, int out_fd);
int		pwd(void *param, int in_fd, int out_fd);
int		export(void *param, int in_fd, int out_fd);
int		unset(void *param, int in_fd, int out_fd);
int		env(void *param, int in_fd, int out_fd);

#endif
