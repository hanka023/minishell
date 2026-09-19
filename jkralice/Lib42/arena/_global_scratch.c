/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _global_scratch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:45:11 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/04 22:30:27 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arena.h"

t_scratch_arenas	*_global_scratch(void)
{
	static __thread t_scratch_arenas	scratch = (t_scratch_arenas){0};

	return (&scratch);
}
