/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:56:08 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/30 19:18:11 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"
#include "../str.h"
#include "../memory.h"

#include <unistd.h>
#include <stdlib.h>

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

char	*relative_to_abs(t_arena *arena, char *str)
{
	char	*out;
	char	*dir;

	dir = getcwd(NULL, 0);
	out = str_cat(arena, (char *[]){dir, str, NULL});
	free(dir);
	return (out);
}

char	*find_executable(t_arena *arena, char *file, char *env_path)
{
	char			*out;
	t_arena_temp	temp;
	char			**paths;
	size_t			size;
	size_t			i;

	if (str_len(file) > 2 && mem_compare(file, "./", 2) == 0)
		return (relative_to_abs(arena, file));
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
