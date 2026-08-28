/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_temp_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:47:56 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/09 15:24:01 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"

inline
void	arena_temp_end(t_arena_temp arena_temp)
{
	arena_pop_to(arena_temp.arena, arena_temp.start_pos);
}
