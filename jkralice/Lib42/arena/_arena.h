/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arena.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:42:42 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/10 00:17:06 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARENA_H
# define _ARENA_H

# include "../arena.h"

typedef struct s_scratch_arenas
{
	t_arena	**arenas;
	size_t	count;
}	t_scratch_arenas;

//	Global pointer to scratch arenas.
//	Ew! Nasty...
t_scratch_arenas	*_global_scratch(void);

#endif
