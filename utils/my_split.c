 //ft_split na steroidech
#include "../minishell.h"

 void word(char *str)
 {
	while (*str)
	{
		*str = 'o';
		write (1, str, 1);
		++str;
	}
	write (1, "\n", 1);

	return;
 }

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

	//printf ("string *str v my_split %s",str);

	while (*str && *str != '\0')
	{
		while (*str && is_in_set(*str, set))
			++str;
		if (!is_in_set(*str, set) && !is_in_set(*str, metachar_set))
		{
			len = print_word(str, &head);
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


