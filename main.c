#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "minishell.h"

int main()
{
	char	*line;
	t_list	*lst;

	while (1)
	{
		write(1, "minishell$ ", 11);
		line = get_next_line(0);
		if(!line)
			return (0);
		lst = my_split(line);
		print_list(&lst);
		free(line);
		free_list (lst);
	}
	return(0);
}