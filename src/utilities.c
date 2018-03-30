/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 03:56:51 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/30 08:54:50 by rzarate          ###   ########.fr       */
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
	get_player_data(game);
}

/*
**	Small functions that returns an array of 
**	2 ints representing width and height
*/

void	get_y_and_x(t_filler *game)
{
	char	**splitted_line;
	char	*line;

	get_next_line(0, &line);
	splitted_line = ft_strsplit(line, ' ');
	game->piece->height = ft_atoi(splitted_line[1]);
	game->piece->width = ft_atoi(splitted_line[2]);
	free(splitted_line[0]);
	free(splitted_line[1]);
	free(splitted_line[2]);
	free(splitted_line);
}
