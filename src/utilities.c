/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 03:56:51 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/02 11:34:41 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Malloc the necessary memory for structures and opening log
**	file for visualizer. Goal is to create a json file for website.
*/

void	initialize_game(t_filler *game)
{
	game->fp = fopen(LOG_FILE, "a+");
	game->player = (t_player *)ft_memalloc(sizeof(t_player));
	game->moves = NULL;
	get_player_data(game);
}

/*
**	Free memory allocated when initializing game
*/

void	finalize_game(t_filler *game)
{
	free(game->player);
	fclose(game->fp);
	free(game);
}

void	end_turn(t_filler *game)
{
	int	i;

	i = -1;
	while (++i < game->board->height)
	{
		ft_strdel(&(game->board->map[i]));
		free(game->board->heatmap[i]);
	}
	free(game->board->map);
	free(game->board->heatmap);
	i = -1;
	while (++i < game->piece->cells)
	{
		free(game->piece->coords[i]);
		free(game->piece->adj_coords[i]);
	}
	free(game->piece->coords);
	free(game->piece->adj_coords);
	i = -1;
	while (++i < game->piece->height)
		ft_strdel(&game->piece->map[i]);
	free(game->piece->map);
	del_moves(&game->moves);
	free(game->board);
	free(game->piece);
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
