/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:40:38 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/06 18:44:54 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../arena.h"

#include <stdlib.h>

t_arena	*arena_create(size_t capacity)
{
	t_arena	*arena;

	arena = malloc(capacity);
	arena->cap = capacity;
	arena->pos = sizeof(t_arena);
	return (arena);
}
