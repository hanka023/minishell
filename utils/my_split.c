 //ft_split na steroidech
#include "../minishell.h"


size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while ((i < (n - 1)) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*my_copy_word(char *start, char *end)
{
	int	j;
	int i;
	int	len;
	char *str0;
	char *str;
	char *set;
	char *copy;
	char c;

	i = 0;
	j = 0;
	c = ' ';
    set = " \n\t";
	copy = NULL;
	str0 = ft_strtrim(copy, set);
	str = spaces(str0, set);

	len = (world_len(str, c));
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
    
    while (j < len)
	{
		copy[i] = start[j];
		++i;
		++j;
	}
	copy[i] = '\0';

	printf ("split@copy_word %s\n", copy);
	printf ("split@copy_word %s\n", end);
	return (copy);
}


t_list *my_split(char  *str)
{
	char	*copy;
	//int		i;
	//int j;
	t_list *head;
	t_list *lst;
	//char *start;

	// char z1 = '\'';
	// char z2 = '\"';
	// char pipe = '|';
	//	char c = ' ';
	// char c1 = '<';
	// char c2 = '>';

	//char *set = " \t\n";
	head = NULL;

	//i = 0;
	int len = 0;
	//j = 0;
	
	char *start;
	int token = 0;
	ssize_t scpy = 0;

	while (*str != '\0')
	{
		
		while (*str == ' ' && *str !='\0')
			++str;
		if (*str != ' ')
		{
			start = str;
			while(*str != ' ' && *str !='\0' )
				++str;
				
		}
		if (*str == ' ')
		{
			len = str - start;
			copy = malloc (sizeof (char) * (len + 1));
			if (copy == NULL)
   				return (NULL);
			scpy = ft_strlcpy (copy, start, len + 1);
			if (!scpy)
				return (0);
			
		
			lst = new_list(copy);
			printf("list %s\n", lst -> str);
		

			add_back(&head, lst); 

			free (copy);
			//printf("token %d %s\n", token, lst-> str);
			++token;
			++str;
		}
		//++str;
	}
	//char *copy_test = str;
	//printf ("testtttt %s\n", str);

//	lst = my_str_to_lst(&head, copy);
//	printf("list v my_split %s\n", lst-> str);

	//lst = my_str_to_lst(&head, copy_test);

	//printf("list v my_split - copy_test %s\n", lst-> str);
	return (head);
}



t_list *my_str_to_lst(t_list **head, char *str)
{
	t_list *lst;

	lst = new_list(str);
	add_back(head, lst); 
		
	return(*head);
}