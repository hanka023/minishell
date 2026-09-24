/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppl_link.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:03:23 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/22 23:35:45 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPL_LINK_H
# define PPL_LINK_H

# include "../types.h"

typedef enum e_ppl_link_type
{
	PPL_TYPE_NONE = 0,
	PPL_TYPE_FUNCTION,
	PPL_TYPE_PROCESS,
}	t_ppl_link_type;

typedef union u_ppl_link_data
{
	struct	s_ppl_link_function
	{
		int		(*foo)(void *param);
		void	*param;
	}	function;
	struct	s_ppl_link_process
	{
		char	*path;
		char	**argv;
		char	**envp;
	}	process;
}	t_ppl_link_data;

typedef struct s_ppl_link
{
	t_ppl_link_type	type;
	t_ppl_link_data	data;
	int				fd[2];
	pid_t			_pid;
}	t_ppl_link;

#endif
