/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:57:11 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/02 18:47:33 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../src/libft/libft.h"
# include <limits.h>

/*
**	STRUCTURES
*/

typedef	struct	s_moves
{
	int				coords[2];
	int				score;
	struct s_moves	*next;
}				t_moves;

typedef	struct	s_player
{
	int		my_n;
	char	my_c;
	char	my_cap_c;
	char	opp_c;
	char	opp_cap_c;
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
	int		**adj_coords;
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
# define ERROR_INITIALIZE "An error ocurred while initializing the game\n"
# define ERROR_TURN "An error occurred while trying to place piece\n"

/*
**	PARSING
*/

void			get_player_data(t_filler *game);
void			get_turn_data(t_filler *game);
void			generate_metadata(t_filler *game);

/*
**	ALGORITHM
*/

int				make_move(t_filler *game);
int				get_score(t_filler *game, int y, int x);
void			create_heatmap(t_filler *game);

/*
**	UTILITIES
*/

void			initialize_game(t_filler *game);
void			finalize_game(t_filler *game);
void			end_turn(t_filler *game);
void			error_exit(t_filler *game, int stage);

t_moves			*new_move(int y, int x, int score);
void			add_move(t_moves **moves, t_moves *new_move);
void			delone_move(t_moves **moves);
void			del_moves(t_moves **moves);

#endif
