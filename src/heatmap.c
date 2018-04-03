/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 08:29:09 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/02 18:43:45 by rzarate          ###   ########.fr       */
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
	game->board->heatmap = (int **)ft_memalloc(sizeof(int *) *
											game->board->height);
	while (++y < game->board->height)
	{
		x = -1;
		game->board->heatmap[y] = (int *)ft_memalloc(sizeof(int) *
											game->board->width);
		while (++x < game->board->width)
		{
			if (game->board->map[y][x] == game->player->my_c ||
					game->board->map[y][x] == game->player->my_cap_c)
				game->board->heatmap[y][x] = -1;
			else if (game->board->map[y][x] == game->player->opp_c ||
					game->board->map[y][x] == game->player->opp_cap_c)
				game->board->heatmap[y][x] = 0;
			else
				game->board->heatmap[y][x] = -10;
		}
	}
}

/*
**	Sets cells values after verifying that we're not gonna go out of boundaries
*/

static	void	set_adyacent_cells(t_board *board, int y, int x, int i)
{
	if (y > 0 && x > 0 && board->heatmap[y - 1][x - 1] < i - 1
			&& board->heatmap[y - 1][x - 1] != -1)
		board->heatmap[y - 1][x - 1] = i + 1;
	if (y > 0 && board->heatmap[y - 1][x] < i - 1
			&& board->heatmap[y - 1][x] != -1)
		board->heatmap[y - 1][x] = i + 1;
	if (y > 0 && x < board->width - 1 && board->heatmap[y - 1][x + 1] < i - 1
			&& board->heatmap[y - 1][x + 1] != -1)
		board->heatmap[y - 1][x + 1] = i + 1;
	if (x > 0 && board->heatmap[y][x - 1] < i - 1
			&& board->heatmap[y][x - 1] != -1)
		board->heatmap[y][x - 1] = i + 1;
	if (x < board->width - 1 && board->heatmap[y][x + 1] < i - 1
			&& board->heatmap[y][x + 1] != -1)
		board->heatmap[y][x + 1] = i + 1;
	if (y < board->height - 1 && x > 0 && board->heatmap[y + 1][x - 1] < i - 1
			&& board->heatmap[y + 1][x - 1] != -1)
		board->heatmap[y + 1][x - 1] = i + 1;
	if (y < board->height - 1 && board->heatmap[y + 1][x] < i - 1
			&& board->heatmap[y + 1][x] != -1)
		board->heatmap[y + 1][x] = i + 1;
	if (y < board->height - 1 && x < board->width - 1
			&& board->heatmap[y + 1][x + 1] < i - 1
			&& board->heatmap[y + 1][x + 1] != -1)
		board->heatmap[y + 1][x + 1] = i + 1;
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

	i = -1;
	initiate_heatmap(game);
	axis = (game->board->height > game->board->width) ?
			game->board->height : game->board->width;
	while (++i < axis - 1)
	{
		y = -1;
		while (++y < game->board->height)
		{
			x = -1;
			while (++x < game->board->width)
			{
				if (game->board->heatmap[y][x] == i)
					set_adyacent_cells(game->board, y, x, i);
			}
		}
	}
}

/*
**	Creates a score of the move by adding up
**	the places occupied in the heatmap
*/

int				get_score(t_filler *game, int y, int x)
{
	int	score;
	int	adj_y;
	int	adj_x;
	int	i;

	score = 0;
	i = -1;
	while (++i < game->piece->cells)
	{
		adj_y = game->piece->adj_coords[i][0];
		adj_x = game->piece->adj_coords[i][1];
		score += game->board->heatmap[y + adj_y][x + adj_x];
	}
	return (score);
}
