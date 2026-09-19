/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:10:52 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/17 22:46:20 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"
#include "../map.h"

void	cleanup(t_state state)
{
	arena_scratch_destroy();
	arena_destroy(state.arena);
	map_free(state.envp);
}
