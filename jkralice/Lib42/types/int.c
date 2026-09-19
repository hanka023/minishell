/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:16:14 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/17 13:58:07 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../types.h"

inline
int	int_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

inline
int	int_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

inline
int	int_abs(int x)
{
	int	mask;

	mask = x >> (sizeof(int) * 8 - 1);
	return ((x + mask) ^ mask);
}

inline
int	int_ternary(int condition, int t, int f)
{
	if (condition)
		return (t);
	else
		return (f);
}
