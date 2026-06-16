
#include <string.h>
#include "parser.h"
#include "../minishell.h"

int quotes_remove (t_list *lst)
{

	while (lst != NULL)
	{
		//printf ("lst -> str %s\n", lst -> str);
		lst = lst -> next;
	}
	return (0);
}