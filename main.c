
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
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
	

	char	*line;
	t_list	*lst;
	int check = 0;

	while (1)
	{
		write(1, "minishell$ ", 11);
		line = get_next_line(0);
		if(!line)
			return (0);
		lst = my_split(line);
		check = checker(lst);

		if (check == 0)
			print_list(lst);
		else if (check == 1)
			printf("bullshit detected \n");
		//print_list(lst);
		expander(lst);
		free(line);
		free_list (lst);
	}
	return(0);
}