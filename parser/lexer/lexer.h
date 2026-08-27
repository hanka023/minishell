/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:37:42 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/27 15:59:23 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../minishell.h"

typedef struct s_list	t_list;
typedef struct s_env	t_env;

/* * * * * * my_split_utils * * * * * */

int		metachar(char *str);
int		stav_str(char *str, int stav);
int		strlen_split(char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
int		strlen_copy(char *str);

/* * * * * * * my_split * * * * * * * * */

char	*make_copy(char *str, int len);
char	*copy_metachar(char *str, int len);
int		no_set(char *str, t_list **head);
int		m_set(char *str, t_list **head);
t_list	*my_split(char *str);

/* * * * * * * quotes * * * * * * * * */

int		quotes(char *str);
int		single_quote(char *str);
int		double_quotes(char *str);

/* * * * * *  * * * word * * * * * * * * */

int		word_to_list(char *str, t_list **head, int len);
void	word_to_list2(char *str, t_list **head, int len);

/* * * * * * * * * * * * * * * * * * * * * * * */

#endif
