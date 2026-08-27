

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*							WARNING !!! THIS CODE IS BUGGY !!!! 								   */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*							start: ./mini						 								   */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/08 17:59:38 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "expander/parser.h"
#include "minishell.h"
#include <sys/wait.h>


// void	free_strings(char **strings);


void line_to_lst(t_env *env, t_state *state)
{

	t_list		*lst;
	char		*line;
	char 		**str;
	char 		**env_str;	
	
	while (1)
	{
		write(1, "minishell$ ", 11);
		line = read_line(&env);
		if(!line)
			break;
		if (check_empty_line(line) == 1)
			continue;
		
		/*  TADY JE TEN LINKED LIST */

		lst = make_lst(line, env, state);

		str = lst_to_str(lst);

		/*                         */

		env_str = env_to_str(env);

	/* print - list pro otestovani */
		print_list (lst); 

	/* test - zmena env */

		printf ("zmena jmena\n");
		char *old = "USER";
		char *new = "111";
		
		change_env_name(env, old, new);
		
		//print_env (env); //  to nechces!!!!

		/*******test     */
	/*  JACHYMUV PUVODNI MAIN */
		//test_execute(ft_strlen_ac(str), str, env_str);
		//free(line);

		free_list(lst);
		free_str(str);
		free_str(env_str);
	
	}
	
}

int main(int argc, char *argv[])
{
	t_env		*env;
	t_state		*state;

	//state = setup(gib(1), 2, mib(32));
	state = NULL;

	(void)argc;
	(void)argv;
	env = env_to_lst();
	line_to_lst(env, state);
	free_env (env);
	
	return(0);
}
