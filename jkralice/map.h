/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:55:56 by pepcen            #+#    #+#             */
/*   Updated: 2026/08/28 14:27:55 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "Lib42/types.h"

//	Duplicates a NULL terminated "key=value" variable list.
//	The list must be free'd with map_free().
char	**map_dup(char **map);

//	Frees the map.
void	map_free(char **map);

//	Prints the entire `map` list to stdout.
void	map_print(char **map);

//	Searches for variable `key` inside `map`.
//	If found returns the pointer to the variable's KEY=VALUE string.
//	If not returns NULL.
char	*map_search(char **map, char *key);

//	Searches for a variable `key` in `map`.
//	If found returns a pointer to the variable's value.
//	If not found returns NULL.
char	*map_get(char **map, char *key);

//	Adds a new variable `key` of the value `val` to `map`.
//	If `val` is NULL, the value is considered to be empty.
//	On success returns the new map list.
//	On failiure returns NULL.
char	**map_add(char **map, char *key, char *val);

//	Removes the variable `key` from `map`.
//	On success returns the new map list.
//	On failiure returns NULL.
char	**map_remove(char **map, char *key);

//	Changes the value of the variable `key` to `val`.
//	If `val` is NULL, the value is considered to be empty.
//	On success returns 1.
//	On failiure returns 0.
int		map_change(char **map, char *key, char *val);

#endif
