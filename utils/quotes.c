#include "../minishell.h"



int quotes(char *str, t_list **head)
{
	int len;

	if (*str == '\'')
		len = single_quote(str, head);
	else if (*str == '"')
		len = double_quotes(str, head);
	return(len);
}

int single_quote(char *str, t_list **head)
{
	int len;
	char *start;
	char *copy;
	char scpy;
	t_list *lst;
	
	start = str;
	len = 0;
	++str;
	while (*str && *str != '\'')
		++str;
	if (*str == '\'')
		++str;
	len = str - start;
	copy = malloc (sizeof (char) * (len + 1));
	if (copy == NULL)
	   	return(0);
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return (0);
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);
	return(len);
}

int double_quotes(char *str, t_list **head)
{
	int len;
	char *start;
	char *copy;
	char scpy;
	t_list *lst;
	
	start = str;
	len = 0;
	++str;
	while (*str && *str != '\"')
		++str;
	if (*str == '\"')
		++str;
	len = str - start;
	copy = malloc (sizeof (char) * (len + 1));
	if (copy == NULL)
	   	return(0);
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return (0);
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);
	return(len);
}


