#include "../minishell.h"

t_list *str_to_lst(int argc, char **argv)
{
	int i;
	long int n;
	t_list *lst;
	t_list *lst1;

	i = 1;
	n = 0;
	lst = NULL;
	lst1 = NULL;
	while(i < argc)
	{

		lst1 = new_list(n);
		add_back(&lst, lst1);
		++i;
	}
	return(lst);
}

t_list *new_list(int value)
{
	t_list *lst;
	lst = malloc (sizeof (t_list));
	if (!lst)
		return (NULL);

	lst -> next = NULL;
	return (lst);
}

void	add_back(t_list **head, t_list *new)
{
	t_list *tmp;

	if (!head || !new)
		return;
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	tmp = *head;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new;
}

void print_list(t_list *begin_list)
{
	t_list *print;

 	print = begin_list;
    while (print != NULL)
    {
       ft_printf("list %d \n",print -> str);
	   print = print -> next;
    }
}

void free_list(t_list *lst)
{
	t_list *free_list;

	while (lst != NULL)
	{
		free_list = (lst) -> next;
		free(lst);
		lst = free_list;
	}
}