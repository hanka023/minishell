/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pipeline.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:56:22 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/26 17:01:34 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PIPELINE_H
# define _PIPELINE_H

# include "../pipeline.h"
# include "pipeline_link.h"
# include "../list/ppl_chain.h"

int	_ppl_run_link_alone(t_ppl_link *link, int in_fd, int out_fd);
int	_ppl_run_link_first(t_ppl_link *link, int in_fd, int out_fd);
int	_ppl_run_link_middle(t_ppl_link *link, int in_fd, int out_fd);
int	_ppl_run_link_last(t_ppl_link *link, int in_fd, int out_fd);

#endif
