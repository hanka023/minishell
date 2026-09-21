/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssize.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:16:14 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/17 13:56:23 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"

inline
ssize_t	ssize_min(ssize_t a, ssize_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

inline
ssize_t	ssize_max(ssize_t a, ssize_t b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

inline
ssize_t	ssize_abs(ssize_t x)
{
	ssize_t	mask;

	mask = x >> (sizeof(ssize_t) * 8 - 1);
	return ((x + mask) ^ mask);
}

inline
ssize_t	ssize_ternary(int condition, ssize_t t, ssize_t f)
{
	if (condition)
		return (t);
	else
		return (f);
}
