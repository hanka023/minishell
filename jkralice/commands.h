/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:27:50 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/29 17:17:20 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

//	ECHO

int		echo(void *param, int in_fd, int out_fd);

typedef struct s_echo_args
{
	int 	argc;
	char	**argv;
}	t_echo_args;

//	CD

int		cd(void *param, int in_fd, int out_fd);

typedef struct s_cd_args
{
	char	*path;
}	t_cd_args;

//	PWD

int		pwd(void *param, int in_fd, int out_fd);

typedef struct s_pwd_argc
{
} t_pwd_args;

//	EXPORT

int		export(void *param, int in_fd, int out_fd);

typedef struct s_export_args
{
	char	***envp;
	char	*key;
	char	*val;
}	t_export_args;

//	UNSET

int		unset(void *param, int in_fd, int out_fd);

typedef struct s_unset_args
{
	char	***envp;
	char	*key;
}	t_unset_args;

//	ENV

int		env(void *param, int in_fd, int out_fd);

typedef struct s_env_args
{
	char	**envp;
}	t_env_args;

#endif
