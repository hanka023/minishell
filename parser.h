/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haskalov <haskalov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:21:20 by haskalov          #+#    #+#             */
/*   Updated: 2026/08/27 14:30:15 by haskalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "parser/gnl/get_next_line.h"
#include "parser/libft/libft.h"
#include "parser/expander/parser.h"
#include "parser/checker/checker.h"
#include "parser/lexer/lexer.h"
#include "parser/main_lst/lst.h"

typedef struct s_list t_list;
typedef struct s_env t_env;
typedef struct s_state t_state;

void line_to_lst(t_env *env, t_state *state);

#endif


