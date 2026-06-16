
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "expander/parser.h"
#include "minishell.h"


void print_envp(char **envp)
{
	int i;

	i = 0;
	while(envp[i] !=NULL)
	{
		printf ("%s\n", envp[i]);
		++i;
	}
	return;
}

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int exp;
	

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
			return (0);
		if(line[0] == '\n' && line[1] == '\0')
		{
			free(line);
			continue;
		}
		check = check_line(line); //ma kontrolovat radek 
		if (check == 1)
		{
			printf("bullshit detected \n");	
			free(line);
			return (1);
		}
		lst = my_split(line);  //splitne line do lst
		exp = expander(lst); 
		if (exp == -1)
			printf("expander ko \n");
		quotes_remove(lst);
		//print_list(lst);
		free_list (lst);
		free(line);
	}
	return(0);
}