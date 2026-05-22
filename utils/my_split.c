 //ft_split na steroidech
#include "../minishell.h"


t_list **my_split(char  *str)
{
	char	*copy;
	t_list **head;
	t_list *lst;
	char *set;
	char *metachar_set;
	int len;
	char *start;
	int token;

	set = " \t\n";
	metachar_set = "|<>";
	head = NULL;
	len = 0;
	token = 0;
	ssize_t scpy = 0;
	start = NULL;
	
	while (*str != '\0')
	{
		while (is_in_set(*str, set) && *str != '\0')
			++str;

		if (!is_in_set(*str, set) && !is_in_set(*str, metachar_set))
		{
			start = str;
			while(!is_in_set(*str, set) && !is_in_set(*str, metachar_set) && *str !='\0')
				++str;	
			len = str - start;
			copy = malloc (sizeof (char) * (len + 1));
			if (copy == NULL)
	   			return (NULL);
			scpy = ft_strlcpy (copy, start, len + 1);
			if (!scpy)
				return (0);
			lst = new_list(copy);
			printf("list v my_split %s\n", lst->str);
			add_back(head, lst); 
			free (copy);
			++token;
		}
		else if (is_in_set(*str, metachar_set))
			metachar(str, head);
	}
	return (head);
}

