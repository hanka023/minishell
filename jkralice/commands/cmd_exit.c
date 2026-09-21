/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:52:14 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/21 15:27:33 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"

#include <stdlib.h>

int	matoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		++i;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = (sign * (-1));
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		++i;
	}
	result = (result * sign);
	return (result);
}

int	cmd_exit(void *param)
{
	t_exit_args	*args;
	int			exit_code;

	args = (t_exit_args *)param;
	if (args->argc > 1)
		exit_code = atoi(args->argv[1]);
	else
		exit_code = 0;
	cleanup(*args->state);
	exit(exit_code);
}
