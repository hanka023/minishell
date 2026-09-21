/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:10:52 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/21 15:54:23 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"
#include "../map.h"

void	cleanup(t_state state)
{
	map_free(state.envp);
	// free_list(state.list);
	arena_scratch_destroy();
	arena_destroy(state.arena);
}
