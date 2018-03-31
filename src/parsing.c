/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 04:03:36 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/31 05:25:28 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Get player number and set the corresponding character
*/

void			get_player_data(t_filler *game)
{
	char	*line;
	
	get_next_line(0, &line);
	game->player->my_n = ft_atoi(ft_strchr(line, 'p') + 1);
	if (game->player->my_n == 1)
	{
		game->player->my_c = 'o';
		game->player->my_C = 'O';
		game->player->opp_n = 2;
		game->player->opp_c = 'x';
		game->player->opp_C = 'X';
	}
	else if (game->player->my_n == 2)
	{
		game->player->my_c = 'x';
		game->player->my_C = 'X';
		game->player->opp_n = 1;
		game->player->opp_c = 'o';
		game->player->opp_C = 'O';
	}
	fprintf(game->fp, "Character: %c - Number: %d\n", game->player->my_c, game->player->my_n);

}
/*
**	Read board's dimensions, parse it and store it in 2d char array
*/

static	void	get_board_data(t_filler *game)
{
	char	*line;
	int		x;
	int		y;
	
	y = -1;
	get_y_and_x(game, 1);
	get_next_line(0, &line);
	game->board->map = (char **)ft_memalloc(sizeof(char *) * game->board->height);
	while (++y < game->board->height)
	{
		x = 3;
		game->board->map[y] = ft_strnew(game->board->width);
		get_next_line(0, &line);
		while (++x < game->board->width + 4)
			game->board->map[y][x - 4] = line[x];
		fprintf(game->fp, "%s\n", game->board->map[y]);
	}
}

/*
**	Read piece's dimensions, parse it and store it in 2d char array
**	gather amount of cells as well for pre-processing
*/

static	void	get_piece_data(t_filler *game)
{
	char	*line;
	int		x;
	int		y;

	y = -1;
	get_y_and_x(game, 2);
	game->piece->map = (char **)ft_memalloc(sizeof(char *) * game->piece->height);
	while (++y < game->piece->height)
	{
		x = -1;
		game->piece->map[y] = ft_strnew(game->piece->width);
		get_next_line(0, &line);
		while (++x < game->piece->width)
		{
			game->piece->map[y][x] = line[x];
			if (game->piece->map[y][x] == '*')
				game->piece->cells++;
		}
		fprintf(game->fp, "%s\n", game->piece->map[y]);
	}
}

/*
**	Single function that controls the flow of the parsing
*/

void			get_turn_data(t_filler *game)
{
	t_piece		*piece;
	t_board		*board;

	piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	board = (t_board *)ft_memalloc(sizeof(t_board));
	game->board = board;
	game->piece = piece;
	get_board_data(game);
	get_piece_data(game);
	// generate_piece_metadata(game);
}
