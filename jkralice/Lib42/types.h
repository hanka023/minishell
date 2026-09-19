/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepcen <pepcen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:03:38 by jkralice          #+#    #+#             */
/*   Updated: 2026/09/17 16:10:09 by pepcen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stddef.h>
# include <sys/types.h>

/* int */

int	int_min(int a, int b);
int	int_max(int a, int b);
int	int_abs(int x);
int	int_ternary(int condition, int t, int f);

/* size_t */

size_t	size_min(size_t a, size_t b);
size_t	size_max(size_t a, size_t b);
size_t	size_ternary(int condition, size_t t, size_t f);
//	Aligns `n` up to the nearest mutiple of `p`.
//	`p` has to be a power of 2.
size_t	size_align_up_pow2(size_t n, size_t p);

/* ssize_t */

ssize_t	ssize_min(ssize_t a, ssize_t b);
ssize_t	ssize_max(ssize_t a, ssize_t b);
ssize_t	ssize_abs(ssize_t x);
ssize_t	ssize_ternary(int condition, ssize_t t, ssize_t f);

#endif
