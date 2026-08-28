/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:42:42 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/09 16:48:34 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../str.h"
#include "../memory.h"

char	*str_sub(t_arena *arena, char *str, size_t start, size_t size)
{
	char	*out;

	out = arena_push(arena, size + 1);
	mem_copy(str + start, out, size);
	out[size] = '\0';
	return (out);
}
