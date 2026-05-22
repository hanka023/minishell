#include "../minishell.h"


void metachar(char *str, t_list **head)
{
	if (*str == '|')
		pipe_char(str, head);
	// else if (*str == '<')
	// 	red_in(str);
	// else if (*str == '>')
	// 	red_out(str);
	return;
}

void pipe_char(char *str, t_list **head)
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
	   	return;
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return ;
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);

	str = str + len;
	return;
}

void red_in(char *str, t_list **head)
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
	   	return;
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return ;
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);

	str = str + len;
	return;
}

void red_out(char *str, t_list **head)
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
	   	return;
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return ;
	lst = new_list(copy);
	add_back(head, lst); 
	free (copy);

	str = str + len;
	return;
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
	   	return;	
	scpy = ft_strlcpy (copy, start, len + 1);
	if (!scpy)
		return;
	lst = new_list(copy);
	printf("list v my_split %s\n", lst -> str);
	add_back(head, lst); 
	free (copy);	
	str = str + len;
	len = 10;
	return(len);
}
