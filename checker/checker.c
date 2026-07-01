
#include <string.h>
#include "checker.h"
#include "../minishell.h"


int check_line(char *str, t_env *env)
{
	int quotes;
	int double_q;
	int pipes;
	int redirect;
	int names;
	
	quotes = 0;
	double_q = 0;
	pipes = 0;
	redirect = 0;
	names = 0;
	
	quotes = check_quotes(str);
	double_q = check_double_quotes(str);
	pipes = check_pipes(str);
	redirect = check_redirect(str);
	names = check_names(str, env);
	if (names !=0)
		printf("* * * * * name KO :( * * * * *\n");
	//printf ("names: %d\n", names);
	if((quotes + double_q + pipes + redirect + names) != 0)
		return (1);
	else 
		return (0);
}
