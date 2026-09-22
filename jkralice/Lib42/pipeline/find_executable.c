/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_executable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:56:08 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 23:33:03 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipeline.h"
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

static inline
char	*find_local_executable(t_arena *arena, char *path)
{
	char	*out;
	char	*cwd;
	size_t	i;

	cwd = getcwd(NULL, 0);
	i = str_len(path);
	while (path[i] != '/')
		i--;
	path = path + i + 1;
	out = str_cat(arena, (char *[]){cwd, "/", path, NULL});
	free(cwd);
	if (access(out, X_OK) == 0)
		return (out);
	return (NULL);
}

char	*find_executable(t_arena *arena, char *file, char *env_path)
{
	char			*out;
	t_arena_temp	temp;
	char			**paths;
	size_t			size;
	size_t			i;

	if (str_len(file) >= 2 && file[0] == '.' && file[1] == '/')
		return (find_local_executable(arena, file));
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
