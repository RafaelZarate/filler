/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 08:29:09 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/31 08:35:09 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	create_heatmap(t_filler *game)
{
	int	y;
	int	x;

	y = -1;
	game->board->heatmap = (int **)ft_memalloc(sizeof(int *) * game->board->height);
	while (++y < game->board->height)
	{
		x = -1;
		while (++x < game->board->width)
		{

		}
	}
}

int	get_score(t_filler *game)
{
	
}
