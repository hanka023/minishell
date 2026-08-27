/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:27:50 by pepcen            #+#    #+#             */
/*   Updated: 2026/05/28 14:02:54 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

void	echo(int argc, char **args);
int		cd(char *path);
int		pwd(void);
char	**export(char **envp, char *key, char *val);
char	**unset(char **envp, char *key);
void	env(char **envp);

#endif
