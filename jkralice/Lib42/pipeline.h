/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:59:31 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/17 23:19:14 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

#include "list/ppl.h"
#include "pipeline/ppl_link.h"

//	Adds a function to the pipeline.
//	When running the pipeline `foo` will be called with `param` as an argument.
//	`fd[2]` stores the in and out descriptor. {0, 1} continues the pipeline.
t_ppl_link	ppl_create_function(
			int (*foo)(void *param), void *param,
			int	fd[2]
			);

//	Adds a process to the pipeline.
//	`path` needs to be a null-terminated string with an absolute path
//	to an executable file on disk.
//	`argv` and `envp` need to follow main() conventions.
//	`fd[2]` stores the in and out descriptor. {0, 1} continues the pipeline.
t_ppl_link	ppl_create_process(
			char *path, char **argv, char **envp,
			int fd[2]
			);

//	Runs the pipeline.
//	Each link of the pipeline chain spawns it's own child process.
//	Returns:
//		 0	-> success
//		-1	-> error
//		+n	-> link n failed to run
ssize_t		ppl_run(t_ppl *ppl, int fd[2]);

//	Waits for all the pipeline's child processes to finish.
//	Returns the exit code of the last process.
int			ppl_wait(t_ppl *ppl);

//	Terminates all pipeline child processes.
void		ppl_stop(t_ppl *ppl);

//	Kills all pipeline child processes.
void		ppl_kill(t_ppl *ppl);

//	Closes all custom file descriptors.
void		ppl_close(t_ppl *ppl);

//	Locates an executable on disk.
//	Return's a null-terminated string with the absolute path to the executable,
//	or NULL on error.
char		*find_executable(t_arena *arena, char *file, char *env_path);

#endif
