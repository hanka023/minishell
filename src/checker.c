
#include <string.h>
#include "parser.h"
#include "../minishell.h"



int check_pipe(t_list *lst)
{
	
	if(lst  && *(lst -> str) == '|')
	
	{
		if(!lst -> next)
		{
			return (1);
		}
	}
	return (0);
}


int checker(t_list *lst)
{
	int bullshit = 0;
	bullshit = check_pipe(lst);

	return(bullshit);
}