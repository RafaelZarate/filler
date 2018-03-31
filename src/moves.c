/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 02:09:54 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/31 06:59:15 by rzarate          ###   ########.fr       */
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
	int	tmp_y;
	int	tmp_x;

	i = -1;
	c = 0;
	while (++i < game->piece->cells)
	{
		tmp_y = y + game->piece->adjusted_coords[i][0];
		tmp_x = x + game->piece->adjusted_coords[i][1];
		if (game->board->map[tmp_x][tmp_y] == game->player->opp_c ||
				game->board->map[tmp_x][tmp_y] == game->player->opp_C)
			return (FALSE);
		else if (game->board->map[tmp_x][tmp_y] == game->player->my_c ||
				game->board->map[tmp_x][tmp_y] == game->player->my_C)
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
				// Calculate score with heatmap
				score = 0;
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
	ft_putnbr(coords_of_best_move[1] - game->piece->head[0]);
	ft_putchar('\n');
}

void	make_move(t_filler *game)
{
	get_possible_moves(game);
	if (!game->moves)
		return ;
	else
		execute_best_move(game);
}