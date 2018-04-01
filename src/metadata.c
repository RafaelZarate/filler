/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 08:18:34 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/01 08:50:03 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Finds and stores coordinates of the piece's cells
*/

static	void	get_piece_coords(t_piece *piece)
{
	int x;
	int y;
	int i;

	i = 0;
	piece->coords = (int **)ft_memalloc(sizeof(int *) * piece->cells);
	y = -1;
	while (++y < piece->height)
	{
		x = -1;
		while (++x < piece->width)
		{
			if (piece->map[y][x] == '*')
			{
				piece->coords[i] = (int *)ft_memalloc(sizeof(int) * 2);
				piece->coords[i][0] = y;
				piece->coords[i][1] = x;
				i++;
			}
		}
	}
}

/*
**	Adjust coordinates relative to the head for easier
**	placing in the board
*/

static	void	adjust_piece_coords(t_piece *piece)
{
	int i;

	i = -1;
	piece->adj_coords = (int **)ft_memalloc(sizeof(int *) * piece->cells);
	while (++i < piece->cells)
	{
		piece->adj_coords[i] = (int *)ft_memalloc(sizeof(int) * 2);
		piece->adj_coords[i][0] = piece->coords[i][0] - piece->coords[0][0];
		piece->adj_coords[i][1] = piece->coords[i][1] - piece->coords[0][1];
	}
}

/*
**	Locate uppermost, lowermost, rightmost and leftmost coordinates
**	Index 0 = uppermost, 1 = lowermost, 2 = rightmost and 3 = leftmost
*/

static	void	get_coords_limits(t_filler *game)
{
	int	i;

	game->piece->uppermost = INT_MAX;
	game->piece->lowermost = INT_MIN;
	game->piece->leftmost = INT_MAX;
	game->piece->rightmost = INT_MIN;
	i = -1;
	while (++i < game->piece->cells)
	{
		if (game->piece->adj_coords[i][0] < game->piece->uppermost)
			game->piece->uppermost = game->piece->adj_coords[i][0];
		if (game->piece->adj_coords[i][0] > game->piece->lowermost)
			game->piece->lowermost = game->piece->adj_coords[i][0];
		if (game->piece->adj_coords[i][1] < game->piece->leftmost)
			game->piece->leftmost = game->piece->adj_coords[i][1];
		if (game->piece->adj_coords[i][1] > game->piece->rightmost)
			game->piece->rightmost = game->piece->adj_coords[i][1];
	}
}

/*
**	Generate piece and board metadata that will be needed to run the algoridthm
*/

void			generate_metadata(t_filler *game)
{
	get_piece_coords(game->piece);
	adjust_piece_coords(game->piece);
	get_coords_limits(game);
	create_heatmap(game);
}
