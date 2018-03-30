/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 03:56:51 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/30 05:14:42 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

/*
**	Malloc the necessary memory for structures and opening log
**	file for visualizer. Goal is to create a json file for website.
*/

void	initialize_game(t_filler *game)
{
	t_piece		*piece;
	t_board		*board;
	
	game->fp = fopen(LOG_FILE, "a");
	piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	board = (t_board *)ft_memalloc(sizeof(t_board));
	get_player_data(game);
}

/*
**	Small functions that returns an array of 
**	2 ints representing width and height
*/

int	*get_y_and_x(char *s)
{
	char	**splitted_line;
	int		*int_arr;

	int_arr = (int *)ft_memalloc(sizeof(int) * 2);
	splitted_line = ft_strsplit(s, ' ');
	int_arr[0] = ft_atoi(splitted_line[1]);
	int_arr[1] = ft_atoi(splitted_line[2]);
	free(splitted_line[0]);
	free(splitted_line[1]);
	free(splitted_line[2]);
	free(splitted_line);
	return (int_arr);
}
