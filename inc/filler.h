/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:57:11 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/31 12:41:37 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../src/libft/libft.h"
#include <limits.h>

/*
**	STRUCTURES
*/

typedef	struct	s_moves
{
	int				coords[2];
	int				score;
	struct	s_moves	*next;
}				t_moves;

typedef	struct	s_player
{
	int		my_n;
	char	my_c;
	char	my_C;
	int		opp_n;
	char	opp_c;
	char	opp_C;
}				t_player;

typedef	struct	s_board
{
	int		width;
	int		height;
	int		center;
	int		center_coords[2];
	char	**map;
	int		**heatmap;
}				t_board;

typedef	struct	s_piece
{
	int		uppermost;
	int		lowermost;
	int		leftmost;
	int		rightmost;
	int		width;
	int		height;
	int		cells;
	int		head[2];
	int		**coords;
	int		**adjusted_coords;
	char	**map;
}				t_piece;

typedef	struct	s_filler
{
	FILE		*fp;
	t_player	*player;
	t_board		*board;
	t_piece		*piece;
	t_moves		*moves;
}				t_filler;

/*
**	MACROS 
*/

# define TRUE 1
# define FALSE 0
# define LOG_FILE "game_log.txt"

/*
**	PARSING
*/

void	get_player_data(t_filler *game);
void	get_turn_data(t_filler *game);
void	generate_metadata(t_filler *game);
/*
**	ALGORITHM
*/

int		make_move(t_filler *game);
int		get_score(t_filler *game, int y, int x);
void	create_heatmap(t_filler *game);

/*
**	VISUALIZER
*/

/*
**	UTILITIES
*/

void	get_y_and_x(t_filler *game, int i);

void	initialize_game(t_filler *game);
void	end_turn(t_filler *game);

t_moves	*new_move(int y, int x, int score);
void	add_move(t_moves **moves, t_moves *new_move);
void	delone_move(t_moves **moves);
void	del_moves(t_moves **moves);

#endif
