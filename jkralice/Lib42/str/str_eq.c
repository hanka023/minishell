/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_eq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 17:08:14 by pepcen            #+#    #+#             */
/*   Updated: 2026/09/17 17:08:16 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../str.h"
#include "../memory.h"

int		str_eq(char *a, char *b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = str_len(a);
	len_b = str_len(b);
	if (len_a == len_b)
		return (mem_compare(a, b, len_a) == 0);
	return (0);
}
