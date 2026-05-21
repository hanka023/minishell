#include "../minishell.h"


void metachar(char *str)
{
	if (*str == '|')
		pipe_char(*str);
	else if (*str == '<')
		red_in(*str);
	else if (*str == '>')
		red_out(*str);
	return;
}

void pipe_char(char *str)
{
	int meta_len;
	char *start;
	char *copy;
	char scpy;
	t_list *lst;
	t_list *head;
	int token;

	meta_len = 1;
	if (*str == '|' && str[1] == '|')
		meta_len = 2;
	start = str;
	copy = malloc (sizeof (char) * (meta_len + 1));
	if (copy == NULL)
	   	return (NULL);
	scpy = ft_strlcpy (copy, start, meta_len + 1);
	if (!scpy)
		return (0);
	lst = new_list(copy);
	add_back(&head, lst); 
	free (copy);
	++token;
	str = str + meta_len;
}


void red_in(char *str)
{
	int meta_len;
	char *start;
	char *copy;
	char scpy;
	t_list *lst;
	t_list *head;
	int token;

	meta_len = 1;
	if (*str == '<' && str[1] == '<')
		meta_len = 2;
	start = str;
	copy = malloc (sizeof (char) * (meta_len + 1));
	if (copy == NULL)
	   	return (NULL);
	scpy = ft_strlcpy (copy, start, meta_len + 1);
	if (!scpy)
		return (0);
	lst = new_list(copy);
	add_back(&head, lst); 
	free (copy);
	++token;
	str = str + meta_len;
}


void red_out(char *str)
{
	int meta_len;
	char *start;
	char *copy;
	char scpy;
	t_list *lst;
	t_list *head;
	int token;

	meta_len = 1;
	if (*str == '>' && str[1] == '>')
		meta_len = 2;
	start = str;
	copy = malloc (sizeof (char) * (meta_len + 1));
	if (copy == NULL)
	   	return (NULL);
	scpy = ft_strlcpy (copy, start, meta_len + 1);
	if (!scpy)
		return (0);
	lst = new_list(copy);
	add_back(&head, lst); 
	free (copy);
	++token;
	str = str + meta_len;
}