/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 02:09:54 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/31 12:42:28 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Verify if piece can be place at the current coordinate
*/

static	int	valid_placement(t_filler *game, int y, int x)
{
	int i;
	int	c;
	int	adj_y;
	int	adj_x;

	i = -1;
	c = 0;
	while (++i < game->piece->cells)
	{
		adj_y = y + game->piece->adjusted_coords[i][0];
		adj_x = x + game->piece->adjusted_coords[i][1];
		if (game->board->map[adj_x][adj_y] == game->player->opp_c ||
				game->board->map[adj_x][adj_y] == game->player->opp_C)
			return (FALSE);
		else if (game->board->map[adj_x][adj_y] == game->player->my_c ||
				game->board->map[adj_x][adj_y] == game->player->my_C)
		{
			if (c > 0)
				return (FALSE);
			c++;
		}
	}
	return (TRUE);
}

/*
**	Iterates through board to find all the possible moves that can be done
**	I used some of the piece's metadata to make sure the program doesn't segfault
**	by looking for a cell outside of the arrays
*/

static	void	get_possible_moves(t_filler *game)
{
	int x;
	int y;
	int	score;

	y = -1;
	while (++y < game->board->height - game->piece->lowermost)
	{
		x = -1 - game->piece->leftmost;
		while (++x < game->board->width - game->piece->rightmost)
		{
			if (valid_placement(game, y, x))
			{
				score = get_score(game, y, x);
				add_move(&(game->moves), new_move(y, x, score));
			}
		}
	}
}

/*
**	Iterates through linked list and locates the move with the highest score
**	and prints the coordinates of this after substracting the off-set
*/

static	void	execute_best_move(t_filler *game)
{
	t_moves *tmp;
	int		score_comp;
	int		coords_of_best_move[2];

	score_comp = INT_MIN;
	tmp = game->moves;
	while (tmp)
	{
		if (tmp->score > score_comp)
		{
			score_comp = tmp->score;
			coords_of_best_move[0] = tmp->coords[0];
			coords_of_best_move[1] = tmp->coords[1];
		}
		tmp = tmp->next;
	}
	ft_putnbr(coords_of_best_move[0] - game->piece->head[0]);
	ft_putchar(' ');
	ft_putnbr(coords_of_best_move[1] - game->piece->head[1]);
	ft_putchar('\n');
}

/*
**	Evaluates map and makes the move with the highest score
**	higher scores are generated when the move gets you closer to the
**	oponent
*/

int		make_move(t_filler *game)
{
	get_possible_moves(game);
	if (!game->moves)
	{
		end_turn(game);
		return (FALSE);
	}
	else
	{
		execute_best_move(game);
		end_turn(game);
		return (TRUE);
	}
}