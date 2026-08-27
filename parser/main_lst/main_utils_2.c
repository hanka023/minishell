/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/27 15:34:02 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parser.h"
#include "../minishell.h"
#include "lst.h"

int	ft_strlen_ac(char **str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str != NULL)
		++*str;
	return (len);
}

int	empty_line(char *line)
{
	int		i;
	char	*set;

	i = 1;
	set = " \n\t";
	while (*line != '\0')
	{
		if (!is_in_set(*line, set))
			i = 0;
		++line;
	}
	return (i);
}

int	check_empty_line(char *line)
{
	int	strlen;

	if (!line || !*line)
		return (0);
	strlen = 0;
	strlen = ft_strlen(line);
	if (strlen >= 1 && (line)[strlen - 1] == '\n')
		(line)[strlen - 1] = '\0';
	if (empty_line(line) == 1)
	{
		free(line);
		return (1);
	}
	return (0);
}

char	*read_line(t_env **env)
{
	char	*line;
	int		check;
	int		fd;

	check = 0;
	fd = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	check = check_line(line, *env);
	if (check == 1)
	{
		printf("chyba na vstupu\n");
		free (line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

t_list	*make_lst(char *line, t_env *env, t_state *state)
{
	t_env	*env;
	t_list	*lst;
	int		exp;

	env = env_to_lst(state->envp);
	exp = 0;
	lst = my_split(line);
	if (!lst)
		return (NULL);
	free (line);
	exp = expander(lst, state->envp, state);
	if (exp == 1)
	{
		printf("Error v expanderu\n");
		free_env (env);
		free_list(lst);
		return (NULL);
	}
	quotes_remove(lst);
	return (lst);
}
