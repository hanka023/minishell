/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:39:54 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/23 21:51:01 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_mini.h"

#include <stdlib.h>

void	argv_add(t_intvars *var, char *str)
{
	char	**argv;
	size_t	i;

	argv = malloc((var->argc + 2) * sizeof(char *));
	i = 0;
	while (i < (size_t)var->argc)
	{
		argv[i] = var->argv[i];
		i++;
	}
	argv[i] = str;
	argv[i + 1] = NULL;
	free(var->argv);
	var->argc++;
	var->argv = argv;
}
