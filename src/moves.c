/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 02:09:54 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/31 05:22:20 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static	int	valid_placement(t_filler *game, int y, int x)
{
	int i;
	int	c;
	int	tmp_y;
	int	tmp_x;

	i = -1;
	c = 0;
	while (++i < game->piece->cells)
	{
		tmp_y = y + game->piece->adjusted_coords[i][0];
		tmp_x = x + game->piece->adjusted_coords[i][1];
		if (game->board->map[tmp_x][tmp_y] == game->player->opp_c ||
				game->board->map[tmp_x][tmp_y] == game->player->opp_C)
			return (FALSE);
		else if (game->board->map[tmp_x][tmp_y] == game->player->my_c ||
				game->board->map[tmp_x][tmp_y] == game->player->my_C)
		{
			if (c > 0)
				return (FALSE);
			c++;
		}
	}
	return (TRUE);
}

static	void	get_possible_moves(t_filler *game)
{
	int x;
	int y;

	y = -1;
	while (++y < game->board->height - game->piece->lowermost)
	{
		x = -1 - game->piece->leftmost;
		while (++x < game->board->width - game->piece->rightmost)
		{
			if (valid_placement(game, y, x))
			{
				
			}
		}
	}
}

void	get_best_move(t_filler *game)
{
	get_possible_moves(game);
}