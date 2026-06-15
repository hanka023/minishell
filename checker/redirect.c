#include <string.h>
#include "checker.h"
#include "../minishell.h"

// int left_dir (char *str, int *count, int *last)
// {
// 	if (*str == '<' && *count == 0 && *(str + 1) == '<')
// 	{
// 		*count = 1;
// 		*last = 0;
// 		++str;
// 	}
// 	else if (*str == '<' && *count == 0 && *(str + 1) != '<')
// 	{
// 		*count = 1;
// 		*last = 1;
// 		++str;
// 	}
// 	else if (*str == '<' && *count == 1)
// 	{
// 		*count = 2;
// 		*last = 1;
// 		++str;
// 	}
// 	else if (*str == '<' && (*count == 2  || *last == 1))
// 	{
// 		return (1);
// 	}
// 	return(*last);
	
// }


int left_dir (char *str, int *left, int *last)
{
	if (!left || !last)
   		return (1);
	else if (*last == 1 || *left == 2)
		return (1); 
	else if ( *left == 0 && *(str + 1) == '<')
	{
		*left = 1;
		*last = 0;
		//++str;
	}
	else if (*left == 0 && *(str + 1) != '<')
	{
		*left = 1;
		*last = 1;
		//++str;
	}
	else if ( *left == 1)
	{
		*left = 2;
		*last = 1;
		//++str;
	}
	return(0);
	
}

int right_dir (char *str, int *right, int *last)
{
	if (!right || !last)
   		return (1);
	if (*last == 1 ||*right == 2 )
		return (1); 
	if ( *right == 0 && *(str + 1) == '<')
	{
		*right = 1;
		*last = 0;
		//++str;
	}
	else if (*right == 0 && *(str + 1) != '<')
	{
		*right = 1;
		*last = 1;
		//++str;
	}
	else if ( *right == 1)
	{
		*right = 2;
		*last = 1;
		//++str;
	}
	return(0);	
}

int left_right_redirect(char *str, int *left, int *right, int *last)
{
	int r;
	int l;

	r = 0;
	l = 0;
	if (*str == '<' && ( *right == 1 || *left == 2))
		return (1);
	else if (*str == '<')
	{
		l = left_dir(str, left, last);
		if (l > 0)
			return (1);
	}
	else if (*str == '>'  && ( *left == 1 || *right == 2))
		return (1);
	else if (*str == '>')
	{
		r = right_dir(str, right, last);
		if (r > 0)
			return(1);
	}
	return (0);

}

int count_redirect(char *str)
{
	int count;
	int redirect;
	int *last;
	int *left;
	int *right;
	int last_value;
	int left_value;
	int right_value;

	left = 0;
	right = 0;
	count = 0;
	last_value = 0;
	left_value = 0;
	right_value = 0;
	last =  &last_value;
	left = &left_value;
	right = &right_value;
	redirect = 0;
	while (*str)
	{
		
		if(*str == '<' || *str == '>')
		{
			redirect = left_right_redirect(str, left, right, last);
			
			if (redirect > 0)
				return (1);
			++str;
		}
		else if (ft_isalnum(*str) == 1)
		{
			*last = 0;
			++str;
		}
		else 
			++str;
		//printf ("last %d\n", *last);
	}
	if (*last == 1)
		return(1);
	return (count);
}


int check_redirect(char *str)
{
	int count;
	int redirect;

	count = 0;
	redirect = 0;
	redirect = count_redirect (str);

	count = redirect;

	if (count > 0)
		return (1);
	else
		return (0);
}