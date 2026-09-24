/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:27:50 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/22 23:19:41 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../mini.h"
# include "../jkralice/mini/_mini.h"

//	Arguments for commands.
typedef struct s_command_args
{
	int		argc;		//	Argument count
	char	**argv;		//	Agruments
	char	***envp;	//	Environment variables (*** for in-place editing)
}	t_command_args;

//	Build it echo command.
//	Flags: `-n`
int		cmd_echo(void *param);

//	Build it cd command.
//	Flags: `none`
int		cmd_cd(void *param);

//	Build in pwd command.
//	Flags: `none`
int		cmd_pwd(void *param);

//	Build in export command.
//	Flags: `none`
int		cmd_export(void *param);

//	Build in unset command.
//	Flags: `none`
int		cmd_unset(void *param);

//	Build in env command.
//	Flags: `none`
int		cmd_env(void *param);

//	Arguments for the exit command
typedef struct s_exit_args
{
	int			argc;		//	Argument count
	char		**argv;		//	Agruments
	t_state		*state;		//	Pointer to state for cleanup.
}	t_exit_args;

//	Built in exit command.
//	Flags: `none`
int		cmd_exit(void *param);

//	Matches `str` to:
//	"echo", "cd", "pwd", "export", "unset", "env", "exit"
//	And returns a pointer to the coresponding command's function.
void	*find_command(char *str);

#endif
