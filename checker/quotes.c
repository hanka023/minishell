
#include <string.h>
#include "../minishell.h"



int check_quotes(char *str)
{
	int quotes;

	quotes = 0; // 0 = ok, 1 = ko
	while (*str)
	{
		if (*str == '\'' && quotes == 0 )
			quotes = 1;
		else if (*str == '\'' && quotes == 1 )
			quotes = 0;
		++str;
	}
	return (quotes);
}


int check_double_quotes(char *str)
{
	int quotes;

	quotes = 0; // 0 = ok, 1 = ko
	while (*str)
	{
		if (*str == '\"' && quotes == 0 )
			quotes = 1;
		else if (*str == '\"' && quotes == 1 )
			quotes = 0;
		++str;
	}
	return (quotes);
}




// int check_line(char *str)
// {
// 	int quotes;
// 	int double_q;
// 	int pipes;
// 	int bullshit;

	
// 	quotes = 0;
// 	double_q = 0;
// 	pipes = 0;
// 	quotes = check_quotes(str);
// 	double_q = check_double_quotes(str);
// 	pipes = check_pipes(str);
	
// 	// printf ("pipes %d\n", pipes);

// 	bullshit = quotes + double_q + pipes;

	
// 	if (bullshit > 0)
// 		return (1);
// 	else 
// 		return (0);
// }
