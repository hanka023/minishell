#include "../minishell.h"

int word(char *str, t_list **head)
{
	int		len;
	char	*set;
	char	*start;
	char	*copy;
	ssize_t	scpy;
	t_list	*lst;

	set = " \t\n|<>";
	start = str;
	while(!is_in_set(*str, set) && *str !='\0')
	{
		len = 0;
		if (*str == '\'' || *str == '"')
		{ 
			len = quotes(str); 
			str = str + len;
		}
		else
			++str;	
	}
	len = str - start;
	//printf("word len%d\n",len );
	copy = malloc (sizeof (char) * (len + 1));
	if (!copy) //<<<<????
	   	return(0);	
	scpy = ft_strlcpy(copy, start, len + 1);
	if (!scpy)
	{
		free(copy);
		return(0);
	}
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);
	str = str + len;
	return(len);
}
