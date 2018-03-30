/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 04:03:36 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/29 21:38:26 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	get_player_data(t_filler *game)
{
	char	*line;
	
	get_next_line(0, &line);
	game->player->n = ft_atoi(ft_strchr(line, 'p') + 1);
	if (game->player->n == 1)
		game->player->c = 'o';
	else if (game->player->n == 2)
		game->player->c = 'x';
	fputc(game->player->c, game->fp);
}

void	get_board_data(t_filler *game)
{
	char	*line;
	char	**splitted_line;
	
	get_next_line(0, &line);
	splitted_line = ft_strsplit(line, ' ');
	game->board->height = ft_atoi(splitted_line[1]);
	game->board->width = ft_atoi(splitted_line[2]);
	free(splitted_line);
}

void	get_turn_data(t_filler *game)
{
	t_piece		*piece;
	t_board		*board;

	piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	board = (t_board *)ft_memalloc(sizeof(t_board));
	game->board = board;
	game->piece = piece;
	get_board_data(game);
}