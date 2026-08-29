/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkralice <jkralice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:52:35 by jkralice          #+#    #+#             */
/*   Updated: 2026/08/29 16:51:48 by jkralice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_pipeline.h"

inline
void	pipeline_clear(t_pipeline *ppl)
{
	ppl_chain_clear((t_ppl_chain *)ppl);
}
