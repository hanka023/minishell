/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:07:15 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/11 10:09:00 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"

t_pipeline	*pipeline_create(t_arena *arena)
{
	return ((t_pipeline *)ppl_chain_create(arena));
}
