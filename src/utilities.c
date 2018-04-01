/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 03:56:51 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/01 09:13:55 by rzarate          ###   ########.fr       */
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
**	Free memory allocated when initializing game
*/

void	finalize_game(t_filler *game)
{
	free(game->board);
	free(game->piece);
	free(game->player);
	fclose(game->fp);
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
		ft_strdel(&game->board->map[i_board]);
		free(game->board->heatmap[i_board]);
	}
	while (++i_coords < game->piece->cells)
	{
		free(game->piece->coords[i_coords]);
		free(game->piece->adj_coords[i_coords]);
	}
	while (++i_piece < game->piece->height)
		ft_strdel(&game->piece->map[i_piece]);
	del_moves(&game->moves);
}

/*
**	This funtion handles errors. It logs the
**	an error, frees all of the memory allocated
**	and exits
*/

void	error_exit(t_filler *game, int stage)
{
	if (stage == 1)
	{
		fprintf(game->fp, ERROR_INITIALIZE);
		finalize_game(game);
		exit(EXIT_FAILURE);
	}
	else if (stage == 2)
	{
		fprintf(game->fp, ERROR_TURN);
		finalize_game(game);
		exit(EXIT_FAILURE);
	}
}
