/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:53:10 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/28 13:51:35 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	jkralice
#include "mini.h"
#include "Lib42/lib42.h"
#include "map.h"

//	stdlib
#include <unistd.h>

int	main(void)
{
	t_state	state;
	t_list	*list;

	state = setup(gib(1), 2, mib(32));

	// while (1)
	// {
		list = parse_input(&state);
		while (list)
		{
			write(1, list->str, str_len(list->str));
			write(1, " ", 1);
			list = list->next;
		}
		write(1, "\n", 1);
	// }
	cleanup(state);
	return (0);
}
