/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_link.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:50:11 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/26 17:02:35 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPELINE_LINK_H
# define PIPELINE_LINK_H

//
//	FILE (LINK)
//

typedef struct s_pipeline_link_file
{
	char		*path;
	int			append;
	int			_fd;
}	t_ppl_link_file;

//
//	FUNCTION (LINK)
//

typedef struct s_pipeline_link_function
{
	int		(*foo)(void *param, int pipe_in, int pipe_out);
	void	*param;
	pid_t	_pid;
}	t_ppl_link_function;

//
//	PROCESS (LINK)
//

typedef struct s_pipeline_link_process
{
	char	*path;
	char	**argv;
	char	**envp;
	pid_t	_pid;
}	t_ppl_link_process;

//
//	LINK
//

//	Link type tag
typedef enum e_pipeline_link_type
{
	PPL_NONE = 0,
	PPL_FILE,
	PPL_FUNCTION,
	PPL_PROCESS
}	t_ppl_link_type;

//	Link data wrapper
typedef union u_pipeline_link_data
{
	t_ppl_link_file		file;
	t_ppl_link_function	function;
	t_ppl_link_process	process;
}	t_ppl_link_data;

//	Link struct
typedef struct s_pipeline_link
{
	t_ppl_link_type	type;
	t_ppl_link_data	data;
}	t_ppl_link;

#endif
