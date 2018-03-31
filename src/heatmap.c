/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 08:29:09 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/31 16:11:13 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Allocate the necessary memory for the heatmap and
**	locate the opponents pieces as well as mine
*/

static	void	initiate_heatmap(t_filler *game)
{
	int	y;
	int	x;

	y = -1;
	game->board->heatmap = (int **)ft_memalloc(sizeof(int *) * game->board->height);
	while (++y < game->board->height)
	{
		x = -1;
		game->board->heatmap[y] = (int *)ft_memalloc(sizeof(int) * game->board->width);
		while (++x < game->board->width)
		{
			if (game->board->map[y][x] == game->player->my_c ||
					game->board->map[y][x] == game->player->my_C)
				game->board->heatmap[y][x] = -2;
			else if (game->board->map[y][x] == game->player->opp_c ||
					game->board->map[y][x] == game->player->opp_C)
				game->board->heatmap[y][x] = -1;
		}
	}
}

/*
**	Sets cells values after verifying that we're not gonna go out of boundaries
*/

static	void	set_adyacent_cells(t_filler *game, int y, int x, int i)
{
	if (y > 0 && x > 0 && game->board->heatmap[y - 1][x - 1] != -2)
		game->board->heatmap[y - 1][x - 1] = i + 1;
	if (y > 0 && game->board->heatmap[y - 1][x] == 0)
		game->board->heatmap[y - 1][x] = i + 1;
	if (y > 0 && x < game->board->width - 1 && game->board->heatmap[y - 1][x + 1] != -2)
		game->board->heatmap[y - 1][x + 1] = i + 1;
	if (x > 0 && game->board->heatmap[y - 1][x - 1] != -2)
		game->board->heatmap[y][x - 1] = i + 1;
	if (x < game->board->width - 1 && game->board->heatmap[y - 1][x + 1] != -2)
		game->board->heatmap[y][x + 1] = i + 1;
	if (y < game->board->height - 1 && x > 0 && game->board->heatmap[y - 1][x - 1] != -2)
		game->board->heatmap[y + 1][x - 1] = i + 1;
	if (y < game->board->height - 1 && game->board->heatmap[y - 1][x - 1] != -2)
		game->board->heatmap[y + 1][x] = i + 1;
	if (y < game->board->height - 1 && x < game->board->width - 1 && game->board->heatmap[y - 1][x - 1] != -2)
		game->board->heatmap[y + 1][x - 1] = i + 1;
}

/*
**	Creates heatmap by giving a value to each cell depending on their proximity
**	a cell ocupied by an opponent
*/

void			create_heatmap(t_filler *game)
{
	int	y;
	int	x;
	int	i;
	int	axis;

	i = -2;
	initiate_heatmap(game);
	axis = (game->board->height >  game->board->width) ?  game->board->height :  game->board->width;
	while (++i < axis)
	{
		y = -1;
		while (++y < game->board->height)
		{
			x = -1;
			while (++x < game->board->width)
			{
				if (game->board->map[y][x] == i)
					set_adyacent_cells(game, y, x, i);
			}
		}
	}
	//printing map for debugging
	y = -1;
	while (++y < game->board->height)
	{
		x = -1;
		while (++x < game->board->width)
			ft_putnbr(game->board->heatmap[y][x]);
		ft_putchar('\n');
	}
}

/*
**	Sums up the value of the cells that gonna be ocupied when the piece is placed
*/

int	get_score(t_filler *game, int y, int x)
{
	int	score;
	int	adj_y;
	int	adj_x;
	int	i;

	score = 0;
	i = -1;
	while (++i < game->piece->cells)
	{
		adj_y = game->piece->adjusted_coords[i][0];
		adj_x = game->piece->adjusted_coords[i][1];
		score += game->board->heatmap[y + adj_y][x + adj_x];
	}
	return (score);
}
