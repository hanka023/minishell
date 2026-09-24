/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:12:51 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 21:19:41 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"
#include "../map.h"
#include "../Lib42/pipeline.h"
#include <stdlib.h>

t_state	setup(
	char **envp,
	size_t arena_size,
	size_t scratch_count,
	size_t scratch_size
)
{
	t_state	out;
	t_arena	*arena;

	arena = arena_create(arena_size);
	arena_scratch_create(scratch_count, scratch_size);
	out = (t_state){
		.arena = arena,
		.envp = map_dup(envp),
		.ppl = ppl_create(arena),
		.exit_code = 0,
		.running = 0
	};
	return (out);
}
