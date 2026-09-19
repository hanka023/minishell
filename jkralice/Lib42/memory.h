/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:17:31 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/06 18:42:04 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "types.h"

//	Copies `n` bytes from `from` to `to`.
void	mem_copy(const void *from, void *to, size_t n);

//	Copies `n` bytes from `from` to `to`.
//	`from` and `to` can overlap.
void	mem_move(void *from, void *to, size_t n);

//	Sets an `n` sized region of memory pointed to by `block` to `byte`.
void	mem_set(void *block, size_t n, char byte);

//	Compares `n` bytes from `a` and `b`.
//	`a > b` -> +bytes compared
//	`a == b` -> 0
//	`a < b` -> -bytes compared
ssize_t	mem_compare(void *a, void *b, size_t n);

//	Searches up to `n` bytes of `block` for `target` of size `t`.
//	Returns pointer to target, or NULL if not found.
void	*mem_search(void *block, size_t n, void *target, size_t t);

size_t	kib(size_t n);
size_t	mib(size_t n);
size_t	gib(size_t n);

#endif
