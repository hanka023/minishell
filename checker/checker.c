
#include <string.h>
#include "checker.h"
#include "../minishell.h"


int check_line(char *str)
{
	int quotes;
	int double_q;
	int pipes;
	int redirect;
	int bullshit;

	
	quotes = 0;
	double_q = 0;
	pipes = 0;
	redirect = 0;
	quotes = check_quotes(str);
	double_q = check_double_quotes(str);
	pipes = check_pipes(str);
	redirect = check_redirect(str);
	// printf ("pipes %d\n", pipes);

	bullshit = quotes + double_q + pipes + redirect;

	
	if (bullshit > 0)
		return (1);
	else 
		return (0);
}
