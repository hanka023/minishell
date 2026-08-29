/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:53:10 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/29 17:01:41 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	jkralice
#include "mini.h"
#include "jkralice/Lib42/lib42.h"

//	stdlib
#include <unistd.h>

int	main(void)
{
	t_state	state;
	t_list	*list;

	state = setup(gib(1), 2, mib(32));
	while (1)
	{
		list = input(&state);
		interpret(&state, list);
		// print_list(list);
		free_list(list);
	}
	cleanup(state);
	return (0);
}
