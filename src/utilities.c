/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 03:56:51 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/31 12:48:05 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Malloc the necessary memory for structures and opening log
**	file for visualizer. Goal is to create a json file for website.
*/

void	initialize_game(t_filler *game)
{
	
	game->board = (t_board *)ft_memalloc(sizeof(t_board));
	game->fp = fopen(LOG_FILE, "a+");
	game->piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	game->player = (t_player *)ft_memalloc(sizeof(t_player));
	game->moves = NULL;
	get_player_data(game);
}

/*
**	Small functions that returns an array of 2 ints representing width and height
**	NOTE: i can only be 1 or 2. 1 is for board and 2 is for piece
*/

void	get_y_and_x(t_filler *game, int i)
{
	char	**splitted_line;
	char	*line;

	get_next_line(0, &line);
	splitted_line = ft_strsplit(line, ' ');
	if (i == 1)
	{
		game->board->height = ft_atoi(splitted_line[1]);
		game->board->width = ft_atoi(splitted_line[2]);
		fprintf(game->fp, "Board height: %d - Board width: %d\n", game->board->height, game->board->width);
	}
	else if (i == 2)
	{
		game->piece->height = ft_atoi(splitted_line[1]);
		game->piece->width = ft_atoi(splitted_line[2]);
		fprintf(game->fp, "Piece height: %d - Piece width: %d\n", game->board->height, game->board->width);
	}
	free(splitted_line[0]);
	free(splitted_line[1]);
	free(splitted_line[2]);
	free(splitted_line);
}

void	end_turn(t_filler *game)
{
	int	i_board;
	int	i_coords;
	int	i_piece;

	i_board = -1;
	i_coords = -1;
	i_piece = -1;
	while (++i_board < game->board->height)
	{
		free(game->board->map[i_board]);
		free(game->board->heatmap[i_board]);
	}
	while (++i_coords < game->piece->cells)
	{
		free(game->piece->coords[i_coords]);
		free(game->piece->adjusted_coords[i_coords]);
	}
	while (++i_piece < game->piece->height)
		free(game->piece->map[i_piece]);
	del_moves(&(game->moves));
}
