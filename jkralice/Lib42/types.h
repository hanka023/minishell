/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:03:38 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/03 11:00:22 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stddef.h>
# include <sys/types.h>

/*	size_t	*/

size_t	size_min(size_t a, size_t b);
size_t	size_max(size_t a, size_t b);

//	Aligns `n` up to the nearest mutiple of `p`.
//	`p` has to be a power of 2.
size_t	size_align_up_pow2(size_t n, size_t p);

/*	ssize_t	*/

ssize_t	ssize_min(ssize_t a, ssize_t b);
ssize_t	ssize_max(ssize_t a, ssize_t b);
ssize_t	ssize_abs(ssize_t x);

/*	byte	*/

typedef unsigned char	t_byte;

#endif
