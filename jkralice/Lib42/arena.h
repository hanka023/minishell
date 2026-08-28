/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:34 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/06 18:47:37 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "types.h"

//	Arena
typedef struct s_arena
{
	size_t	cap;
	size_t	pos;
}	t_arena;

//	Creates a new arena with `cap` capacity.
t_arena			*arena_create(size_t cap);

//	Free's the arena's memory.
void			arena_destroy(t_arena *arena);

//	Pushes `n` bytes onto the arena.
void			*arena_push(t_arena *arena, size_t n);

//	Adds `n` more bytes to the last allocated block of memory
//	by advancing the arenas position.
//	Returns the number of bytes succesfully added.
size_t			arena_advance(t_arena *arena, size_t n);

//	Pops `n` bytes off the arena.
void			arena_pop(t_arena *arena, size_t n);

//	Pops the arena to position `pos`.
void			arena_pop_to(t_arena *arena, size_t pos);

//	Cleares the entire arena.
void			arena_clear(t_arena *arena);

/* Temporary arena */
typedef struct s_arena_temp
{
	t_arena	*arena;
	size_t	start_pos;
}				t_arena_temp;

//	Saves the state of `arena`.
t_arena_temp	arena_temp_begin(t_arena *arena);

//	Restores the state of `arena`.
void			arena_temp_end(t_arena_temp arena_temp);

/* Scratch arena */

//	Creates `n` scratch arenas.
//	Returns the number of succesfully created arenas.
size_t			arena_scratch_create(size_t n, size_t capacity);

//	Returns a temporary arena if no conflicts are found.
//	Else it returns an empty temp arena.
t_arena_temp	arena_scratch_claim(size_t n, t_arena **conflicts);

//	Releases a temporary scratch arena.
void			arena_scratch_release(t_arena_temp scratch);

//	Destroys scatch arenas.
void			arena_scratch_destroy(void);

#endif
