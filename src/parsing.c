/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 04:03:36 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/01 09:15:18 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Gets width and heigh
*/

static	void	get_y_and_x(int *y, int *x, t_filler *game)
{
	char	**splitted_line;
	char	*line;

	if (get_next_line(0, &line) > 0 && ft_countwords(line, ' ') == 3)
	{
		splitted_line = ft_strsplit(line, ' ');
		*y = ft_atoi(splitted_line[1]);
		*x = ft_atoi(splitted_line[2]);
		if (!ft_isdigit(splitted_line[1][0]) || !ft_isdigit(splitted_line[2][0])
				|| *y == 0 || *x == 0)
		{
			ft_2d_strdel(splitted_line, 3);
			ft_strdel(&line);
			error_exit(game, 2);
		}
		ft_2d_strdel(splitted_line, 3);
		ft_strdel(&line);
	}
	else
		error_exit(game, 2);
}

/*
**	Get player number and set the corresponding character
*/

void			get_player_data(t_filler *game)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
	{
		if (ft_strchr(line, 'p'))
			game->player->my_n = ft_atoi(ft_strchr(line, 'p') + 1);
		ft_strdel(&line);
	}
	if (game->player->my_n == 1)
	{
		game->player->my_c = 'o';
		game->player->my_C = 'O';
		game->player->opp_c = 'x';
		game->player->opp_C = 'X';
	}
	else if (game->player->my_n == 2)
	{
		game->player->my_c = 'x';
		game->player->my_C = 'X';
		game->player->opp_c = 'o';
		game->player->opp_C = 'O';
	}
	else
		error_exit(game, 1);
}

/*
**	Read board's dimensions, parse it and store it in 2d char array
*/

static	void	get_board_data(t_board *board, t_filler *game)
{
	char	*line;
	int		x;
	int		y;

	y = -1;
	get_y_and_x(&(board->height), &(board->width), game);
	get_next_line(0, &line);
	ft_strdel(&line);
	board->map = (char **)ft_memalloc(sizeof(char *) * board->height);
	while (++y < board->height)
	{
		x = 3;
		(!(get_next_line(0, &line) > 0)) ? error_exit(game, 2) : 0;
		if ((int)ft_strlen(line) != board->width + 4)
		{
			ft_strdel(&line);
			error_exit(game, 2);
		}
		board->map[y] = ft_strsub(line, 4, board->width);
		fprintf(game->fp, "%s\n", board->map[y]);
		ft_strdel(&line);
	}
}

/*
**	Read piece's dimensions, parse it and store it in 2d char array
**	gather amount of cells as well for pre-processing
*/

static	void	get_piece_data(t_piece *piece, t_filler *game)
{
	char	*line;
	int		x;
	int		y;

	y = -1;
	get_y_and_x(&(piece->height), &(piece->width), game);
	piece->map = (char **)ft_memalloc(sizeof(char *) * piece->height);
	while (++y < piece->height)
	{
		x = -1;
		(!(get_next_line(0, &line) > 0)) ? error_exit(game, 2) : 0;
		if ((int)ft_strlen(line) != piece->width)
		{
			ft_strdel(&line);
			error_exit(game, 2);
		}
		piece->map[y] = ft_strnew(piece->width);
		while (++x < piece->width)
		{
			piece->map[y][x] = line[x];
			if (piece->map[y][x] == '*')
				piece->cells++;
		}
		ft_strdel(&line);
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
	get_board_data(game->board, game);
	get_piece_data(game->piece, game);
	generate_metadata(game);
}
