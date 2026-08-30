/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:20:41 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/30 16:32:40 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commands.h"
#include "../Lib42/types.h"

void	separate_key_val(char *str, char **key_out, char **val_out)
{
	size_t	i;

	*key_out = str;
	*val_out = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			str[i] = '\0';
			*val_out = &(str[i + 1]);
			return ;
		}
		i++;
	}
}
