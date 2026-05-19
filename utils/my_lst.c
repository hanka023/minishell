
#include "../minishell.h"

char *copy_world3(char *start, char *end)
{
	int len;

	len = 0;
	while (start != end)
	{
		++start;
		++len;
	}
	printf("delka stringu %d\n", len - 1);

	return (NULL);
}


t_list *char_to_lst(char *str, char *end)
{
	
	//char *end;
//	t_list *lst;
	// lst = NULL;

	end = str;
	while (*end != '\0')
		++end;

	copy_world3(str, end);

	return (NULL);
}


void my_lst(char *str)
{
	char *s = "hello";
	char *end;
	// t_list *lst;
	// lst = NULL;

	end = s;
	while (*end != '\0')
		++end;

	copy_world3(s, end);
	
	printf ("puvodni str %s\n", str);
	return;
}