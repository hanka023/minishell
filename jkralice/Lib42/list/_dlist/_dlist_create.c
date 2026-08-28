/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dlist_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:56:34 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/06 16:21:43 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dlist.h"

struct s_dlist	*_dlist_create(t_arena *arena)
{
	struct s_dlist	*out;

	out = arena_push(arena, sizeof(struct s_dlist));
	*out = (struct s_dlist){
		.arena = arena,
		.start = NULL,
		.end = NULL,
		.size = 0
	};
	return (out);
}
