#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "minishell.h"

int main()
{
	char *line;
	t_list *lst;
	//int nb;
	//char **arr;
	char *set;
	//char c;

	
	//arr = NULL;
	set = " \n\t";
	//c = ' ';
	while (1)
	{
		
		write(1, "minishell$ ", 11);
		line = get_next_line(0);
		if(!line)
			return (0);

		line = ft_strtrim(line, set);
		line = spaces(line, set);

		lst = my_split(line);

		//arr = ft_split(line, c);
		// nb = count_words(line, c);
		// lst = str_to_lst( nb,arr);
		
		print_list(lst);

		//my_lst(line);


		free(line);
		free_list (lst);
	}
}