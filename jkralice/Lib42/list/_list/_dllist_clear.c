/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dllist_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:21:25 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/07 21:40:16 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dllist.h"

void	_dllist_clear(t_dllist *list)
{
	if (list->size)
	{
		if (list->free)
			__dllnode_data(list->free)->prev = list->end;
		__dllnode_data(list->end)->next = list->free;
		list->free = list->start;
		list->start = NULL;
		list->end = NULL;
		list->size = 0;
	}
}
