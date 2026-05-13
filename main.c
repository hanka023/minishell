#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "minishell.h"

int main()
{
	char *line;
	char **arr;
	char *set = " \n\t";
	char *trim;
	//char *trim2;
	char c;
	int i;
	t_list *lst;

	c = ' ';
	i = 0;
	
	while (1)
	{
		i = 0;
		write(1, "minishell$ ", 11);
		line = get_next_line(0);
		if(!line)
			return (0);

		arr = ft_split(line, c);

		while (arr[i] != NULL)
		{
			trim = ft_strtrim(arr[i], set);
			//trim2 = spaces(trim, set);
			//printf("str[i] >>>>> %s\n", trim);
			lst = str_to_lst(trim);
			
			printf ("%s \n", lst -> str);
			free(arr[i]);
			free(trim);
			//free(trim2);
			++i;
		}
		free(arr);
		free(line);
		free_list (lst);
	}
}