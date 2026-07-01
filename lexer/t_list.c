#include "../minishell.h"


t_list *str_to_lst(int argc, char **argv)
{
	int i;

	t_list *head;
	t_list *lst;

	i = 0;
	head = NULL;
	lst = NULL;
	while(i < argc)
	{
		lst = new_list(argv[i]);
		add_back(&head, lst); 
		++i;
	}
	return(head);
}

t_list *new_list(char *str)
{
	t_list *lst;
	
	lst = malloc (sizeof (t_list));
	if (!lst)
		return (NULL);
	lst -> str = ft_strdup(str);
	if (!lst -> str)
	{
		free(lst);
		return (NULL);
	}
	lst -> next = NULL;
	return (lst);
}

void	add_back(t_list **head, t_list *lst)
{
	t_list *tmp;

	if (!head || !lst)
		return;
	if (*head == NULL)
	{
		*head = lst;
		return;
	}
	tmp = *head;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = lst;
	return;
}

void print_list(t_list *lst)
{
	
    while ( lst != NULL)
    {
      	printf("%s\n", lst -> str);
	   	lst = lst -> next;
    }
	return;
}

void free_list(t_list *lst)
{
	t_list *free_list;

	while (lst != NULL)
	{
		free_list = (lst) -> next;
		if (lst -> str != NULL)
			free (lst -> str);
		free(lst);
		lst = free_list;
	}
	return;
}