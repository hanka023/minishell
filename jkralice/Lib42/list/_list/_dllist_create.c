/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dllist_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:56:34 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/07 17:02:25 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dllist.h"

t_dllist	*_dllist_create(t_arena *arena)
{
	t_dllist	*out;

	out = arena_push(arena, sizeof(t_dllist));
	*out = (t_dllist){
		.arena = arena,
		.start = NULL,
		.end = NULL,
		.free = NULL,
		.size = 0
	};
	return (out);
}
