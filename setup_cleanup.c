/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:12:51 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/27 15:57:05 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include "map.h"
#include "Lib42/pipeline.h"
#include <stdlib.h>

extern char **environ;

t_state	setup(size_t arena_size, size_t scratch_count, size_t scratch_size)
{
	char		**envp_dup;
	t_arena		*arena;
	t_pipeline	*pipeline;

	envp_dup = map_dup(environ);
	arena = arena_create(arena_size);
	arena_scratch_create(scratch_count, scratch_size);
	pipeline = pipeline_create(arena);
	return (t_state){
		.envp = envp_dup,
		.arena = arena,
		.pipeline = pipeline,
		.exit_code = 0
	};
}

void	cleanup(t_state state)
{
	arena_scratch_destroy();
	arena_destroy(state.arena);
	free(state.envp);
}
