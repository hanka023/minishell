/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:27:15 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/24 15:16:57 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "arena.h"

//	Return's the string's lenght. (index of null-terminator)
size_t	str_len(char *str);

//	Contatenates together strings in a NULL-terminated array.
char	*str_cat(t_arena *arena, char **strs);

//	Creates a substring out of `str`.
char	*str_sub(t_arena *arena, char *str, size_t start, size_t size);

//	Splits `str` using `c` as the character delimiter.
char	**str_split(t_arena *arena, char *str, char c);

#endif
