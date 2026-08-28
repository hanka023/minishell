/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:48:01 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/26 17:01:23 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_H
# define PIPELINE_H

# include "arena.h"

typedef struct s_ppl_chain	t_pipeline;

//	Creates an empty pipline.
t_pipeline	*pipeline_create(t_arena *arena);

//	Adds a function to the pipeline.
//	Keep in mind that pipeline functions run as a separate process.
//	This is better for io-bound or otherwise blocking functions,
//	because the CPU scheduler can parallelise the processes,
//	but for non blocking functions it's better to move them out of the pipeline.
//	Returns 0 on error.
int			pipeline_add_function(
				t_pipeline *ppl,
				int (*foo)(void *param, int in_fd, int out_fd),
				void *param
				);

//	Adds a process to the pipeline.
//	`path` needs to be a null-terminated string with an absolute path
//	to an executable file on disk.
//	Returns 0 on error.
int			pipeline_add_process(
				t_pipeline *ppl,
				char *path,
				char **argv,
				char **envp
				);

//	Runs the pipeline.
//	Each link of the pipeline chain spawns it's own child process.
//	Returns:
//		 0	-> success
//		-1	-> error
//		+n	-> link n failed to run
int			pipeline_run(t_pipeline *ppl, int in_fd, int out_fd);

//	Waits for all the pipeline's child processes to finish.
//	Returns the exit code of the last process.
int			pipeline_wait(t_pipeline *ppl);

//	Terminates all pipeline child processes.
void		pipeline_stop(t_pipeline *ppl);

//	Kills all pipeline child processes.
void		pipeline_kill(t_pipeline *ppl);

//	Clears the pipeline.
void		pipeline_clear(t_pipeline *ppl);

//	Locates an executable on disk.
//	Return's a null-terminated string with the absolute path to the executable,
//	or NULL on error.
char		*find_executable(t_arena *arena, char *file, char *env_path);

#endif
