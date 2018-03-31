/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked-list-funtions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 06:07:04 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/31 06:31:53 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	These functions are pretty self explanatory but just in case.
**	new_move - creates a new node and stores coordinates and score
**	add_move - adds a new node (move) to the linked list (moves)
**	delone_move - deletes a node, I probably won't use this
**	del_moves - deletes the entire linked list
*/

t_moves	*new_move(int y, int x, int score)
{
	t_moves	*move;

	move = (t_moves *)ft_memalloc(sizeof(t_moves));
	if (!move)
		return (NULL);
	move->score = score;
	move->coords[0] = y;
	move->coords[1] = x;
	return (move);
}

void	add_move(t_moves **moves, t_moves *new_move)
{
	if (moves && *moves && new_move)
	{
		new_move->next = *moves;
		*moves = new_move;
	}
	else if (new_move && (!moves || !(*moves)))
		*moves = new_move;
}

void	delone_move(t_moves **moves)
{
	t_moves	*tmp;

	if (moves && *moves)
	{
		tmp = *moves;
		*moves = (*moves)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	del_moves(t_moves **moves)
{
	while (*moves)
		delone_move(moves);
}
