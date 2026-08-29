/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _dlist_getters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:06:06 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/29 17:03:36 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_dlist.h"

inline
struct s_dnode	*_dlist_start(struct s_dlist *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->start);
}

inline
struct s_dnode	*_dlist_end(struct s_dlist *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->end);
}

inline
size_t	_dlist_size(struct s_dlist *list)
{
	return (list->size);
}
