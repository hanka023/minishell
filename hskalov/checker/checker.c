/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/08 18:11:19 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../minishell.h"

int	check_line(char *str, t_env *env)
{
	int	quotes;
	int	double_q;
	int	pipes;
	int	redirect;
	int	names;

	quotes = 0;
	double_q = 0;
	pipes = 0;
	redirect = 0;
	names = 0;
	quotes = check_quotes(str);
	double_q = check_double_quotes(str);
	pipes = check_pipes(str);
	redirect = check_redirect(str);
	names = check_names(str, env);
	if (names != 0)
	{
		printf("Error: no name\n");
	}
	if ((quotes + double_q + pipes + redirect + names) != 0)
		return (1);
	else
		return (0);
}
