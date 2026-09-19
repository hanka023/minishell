/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:50:51 by pepcen            #+#    #+#             */
/*   Updated: 2026/06/09 16:40:03 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory.h"

inline
size_t	kib(size_t n)
{
	return (n << 10);
}

inline
size_t	mib(size_t n)
{
	return (n << 20);
}

inline
size_t	gib(size_t n)
{
	return (n << 30);
}
