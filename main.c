
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "expander/parser.h"
#include "minishell.h"


// void print_envp(char **envp)
// {
// 	int i;

// 	i = 0;
// 	while(envp[i] !=NULL)
// 	{
// 		printf ("%s\n", envp[i]);
// 		++i;
// 	}
// 	return;
// }



// void error_handle(t_list *lst, t_env *env)
// {
// 	printf("Error detected\n");
// 	free_env (env);
// 	free_list(lst);
// 	return;
// }





int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int exp;
	t_env *env;

	env = env_to_lst();
	char	*line;
	t_list	*lst;
	
	int check;

	
	check = 0;
	exp = 0;
	
	while (1)
	{
		check = 0;
		write(1, "minishell$ ", 11);
		line = get_next_line(0);
		if(!line)
		{
			free(line);
			free_env(env);
			return (0);
		}
		if(line[0] == '\n' && line[1] == '\0')
		{
			free(line);
			continue;
		}
		check = check_line(line); //ma kontrolovat radek 
		if (check == 1)
		{
			printf("chyba na vstupu\n");	
			free(line);
			free_env(env);
			return (1);
		}
		lst = my_split(line);  //splitne line do lst
		exp = expander(lst, env); 
		if (exp == 1)
		{
			printf("Error v expanderu\n");
			free_env (env);
			free_list(lst);
			free(line);
			//error_handle(lst, env);
			return (1);
		}
		quotes_remove(lst);
		print_list(lst);
		free_list (lst);
		
		free(line);
	}

	free_env(env);

	
	return(0);
}
