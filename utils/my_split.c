 //ft_split na steroidech
#include "../minishell.h"



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
	int		i;
	//int j;
	t_list *head;
	t_list *lst;
	//char *start;

	// char z1 = '\'';
	// char z2 = '\"';
	// char pipe = '|';
	// char c = ' ';
	// char c1 = '<';
	// char c2 = '>';

	//char *set = " \t\n";
	head = NULL;
	copy = str;
	i = 0;
	int len = 0;
	//j = 0;
	
	// char *start;
	// char *end;

	// start = str;
	

	while (str[i] != '\0')
	{
		if (str[i] == '\"')
		{
			++i;
			while(str[i] != '\'' && str[i] !='\0')
				++i;
			if  (str[i] == '\"')
				++i;
			
		}	
		else if (str[i] == '\'')
		{
			++i;
			while(str[i] != '\'' && str[i] !='\0')
				++i;
			if  (str[i] == '\'')
				++i;
			
		}	
		else if (str[i] != ' ')
		{
			while (str[i] !=' ')
				++i;
		}
		if (str[i] == ' ')
		{
			len = i;
			i = 0;
			while (i < len)
			{
				copy[i] = str[i];
				++i;
			}
			copy[i] = '\0';
			lst = my_str_to_lst(&head, copy);
			printf("token %s\n", lst-> str);

		}
	}

	char *copy_test = str;
	//printf ("testtttt %s\n", str);

//	lst = my_str_to_lst(&head, copy);
//	printf("list v my_split %s\n", lst-> str);

	lst = my_str_to_lst(&head, copy_test);

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