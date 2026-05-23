#include "../minishell.h"


int metachar(char *str, t_list **head)
{
	int len;


	if (*str == '|')
		len = pipe_char(str, head);
	else if (*str == '<')
		red_in(str, head);
	else if (*str == '>')
		red_out(str, head);
	return(len);
}

int pipe_char(char *str, t_list **head)
{
	int len;
	char *start;
	char *copy;
	char scpy;
	t_list *lst;
	
	start = str;
	len = 1;
	if (*str == '|' && str[1] == '|')
		len = 2;
	copy = malloc (sizeof (char) * (len + 1));
	if (copy == NULL)
	   	return(0);
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return (0);
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);

	str = str + len;
	return(len);
}

int red_in(char *str, t_list **head)
{
	int len;
	char *start;
	char *copy;
	char scpy;
	t_list *lst;
	
	start = str;
	len = 1;
	if (*str == '<' && str[1] == '<')
		len = 2;
	copy = malloc (sizeof (char) * (len + 1));
	if (copy == NULL)
	   	return(0);
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return (0);
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);

	str = str + len;
	return(len);
}

int red_out(char *str, t_list **head)
{
	int len;
	char *start;
	char *copy;
	char scpy;
	t_list *lst;
	
	start = str;
	len = 1;
	if (*str == '>' && str[1] == '>')
		len = 2;
	copy = malloc (sizeof (char) * (len + 1));
	if (copy == NULL)
	   	return(0);
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return(0);
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);

	str = str + len;
	return (len);
}

int print_word(char *str, t_list **head)
{
	int len;
	char *set;
	char *start;
	char *metachar_set;
	char *copy;
	ssize_t scpy;
	t_list *lst;

	set = " \t\n";
	metachar_set = "|<>";
	len = 0;
	start = str;
	while(!is_in_set(*str, set) && !is_in_set(*str, metachar_set) && *str !='\0')
		++str;	
	len = str - start;
	copy = malloc (sizeof (char) * (len + 1));
	if (copy == NULL)
	   	return(0);	
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return(0);
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);	
	str = str + len;

	return(len);
}
