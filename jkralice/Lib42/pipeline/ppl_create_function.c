/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_create_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:08:40 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/17 15:48:34 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipeline.h"

t_ppl_link	ppl_create_function(int (*foo)(void *), void *param, int fd[2])
{
	t_ppl_link	link;

	{
		link.type = PPL_TYPE_FUNCTION;
		link.data.function.foo = foo;
		link.data.function.param = param;
		link.fd[0] = fd[0];
		link.fd[1] = fd[1];
		link._pid = 0;
	}
	return (link);
}
