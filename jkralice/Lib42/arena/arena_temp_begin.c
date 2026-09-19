/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_temp_begin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:47:56 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/06 18:49:32 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"

inline
t_arena_temp	arena_temp_begin(t_arena *arena)
{
	return ((t_arena_temp){
		.arena = arena,
		.start_pos = arena->pos}
		);
}
