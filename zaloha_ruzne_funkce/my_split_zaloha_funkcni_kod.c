 //ft_split na steroidech
#include "../minishell.h"


// char	*my_copy_word(char *start, char *end)
// {
// 	int	j;
// 	int i;
// 	int	len;
// 	char *str0;
// 	char *str;
// 	char *set;
// 	char *copy;
// 	char c;

// 	i = 0;
// 	j = 0;
// 	c = ' ';
//     set = " \n\t";
// 	copy = NULL;
// 	str0 = ft_strtrim(copy, set);
// 	str = spaces(str0, set);

// 	len = (world_len(str, c));
// 	copy = malloc(sizeof(char) * (len + 1));
// 	if (!copy)
// 		return (0);
    
//     while (j < len)
// 	{
// 		copy[i] = start[j];
// 		++i;
// 		++j;
// 	}
// 	copy[i] = '\0';

// 	printf ("split@copy_word %s\n", copy);
// 	printf ("split@copy_word %s\n", end);
// 	return (copy);
// }

t_list *my_split(char  *str)
{
	char	*copy;
	t_list *head;
	t_list *lst;
	char *set;
	char *metachar;
	int len;
	char *start;
	int token;

	set = " \t\n";
	metachar = "|<>";
	head = NULL;
	len = 0;
	token = 0;
	ssize_t scpy = 0;
	start = NULL;
	
	while (*str != '\0')
	{
		while (is_in_set(*str, set) && *str != '\0')
			++str;

		if (!is_in_set(*str, set) && !is_in_set(*str, metachar))
		{
			start = str;
			while(!is_in_set(*str, set) && !is_in_set(*str, metachar) && *str !='\0')
				++str;	
			len = str - start;
			copy = malloc (sizeof (char) * (len + 1));
			if (copy == NULL)
	   			return (NULL);
			scpy = ft_strlcpy (copy, start, len + 1);
			if (!scpy)
				return (0);
			lst = new_list(copy);
			add_back(&head, lst); 
			free (copy);
			++token;
		}
		else if (is_in_set(*str, metachar))
		{
			if (*str == '|')
			{
				int meta_len = 1;
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
				else if (*str == '<')
			{
				int meta_len = 1;
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
				else if (*str == '>')
			{
				int meta_len = 1;
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

		}
	}
	return (head);
}

