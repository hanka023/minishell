/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 14:10:52 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/28 14:55:13 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mini.h"

void	cleanup(t_state state)
{
	arena_scratch_destroy();
	arena_destroy(state.arena);
	free(state.envp);
}
