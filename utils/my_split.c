 //ft_split na steroidech
#include "../minishell.h"


t_list *my_split(char  *str)
{
	t_list *head;
	char *set;
	char *metachar_set;
	int len;

	set = " \t\n";
	metachar_set = "|<>";
	head = NULL;
	len = 0;
	while (*str && *str != '\0')
	{
		while (*str && is_in_set(*str, set))
			++str;
		
		if (!is_in_set(*str, set) && !is_in_set(*str, metachar_set))
		{
			len = word(str, &head);
			str = str + len;
		}
		else if (is_in_set(*str, metachar_set))
		{
			len = metachar(str, &head);
			str = str + len;
		}
	}
	return (head);
}


