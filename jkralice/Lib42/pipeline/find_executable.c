/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:56:08 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/24 16:28:08 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"
#include "../str.h"
#include "../memory.h"

#include <unistd.h>

static inline
char	**get_paths(t_arena *arena, char *file, char *env_path)
{
	char	**out;
	size_t	i;

	out = str_split(arena, env_path, ':');
	i = 0;
	while (out[i])
	{
		out[i] = str_cat(arena, (char *[]){
				out[i], "/", file,
				NULL});
		i++;
	}
	return (out);
}

char	*find_executable(t_arena *arena, char *file, char *env_path)
{
	char			*out;
	t_arena_temp	temp;
	char			**paths;
	size_t			size;
	size_t			i;

	out = NULL;
	temp = arena_scratch_claim(1, &arena);
	paths = get_paths(temp.arena, file, env_path);
	i = 0;
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			size = str_len(paths[i]) + 1;
			out = arena_push(arena, size);
			mem_copy(paths[i], out, size);
			break ;
		}
		i++;
	}
	arena_scratch_release(temp);
	return (out);
}
