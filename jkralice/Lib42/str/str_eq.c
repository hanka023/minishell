/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_eq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:16:26 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/29 15:20:23 by jkralice         ###   ########.fr       */
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
