/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:10:52 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/22 21:35:10 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"
#include "../map.h"

#include <readline/readline.h>

void	cleanup(t_state state)
{
	rl_clear_history();
	map_free(state.envp);
	arena_scratch_destroy();
	arena_destroy(state.arena);
}
