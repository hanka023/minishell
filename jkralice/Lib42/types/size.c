/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:13:44 by jkralice          #+#    #+#             */
/*   Updated: 2026/06/10 00:15:33 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"

inline
size_t	size_min(size_t a, size_t b)
{
	return (a ^ (a > b) * (a ^ b));
}

inline
size_t	size_max(size_t a, size_t b)
{
	return (a ^ (a < b) * (a ^ b));
}

inline
size_t	size_align_up_pow2(size_t n, size_t p)
{
	return ((n + (p - 1)) & (~(p - 1)));
}
