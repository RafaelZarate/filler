/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:58:01 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/29 21:12:16 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	initialize_game(t_filler *game)
{
	t_piece		*piece;
	t_board		*board;

	game->fp = fopen(LOG_FILE, "w");
	piece = (t_piece *)ft_memalloc(sizeof(t_piece));
	board = (t_board *)ft_memalloc(sizeof(t_board));

	get_player_data(game);
}

int	main(void)
{
	t_filler	*game;
	
	game = (t_filler *)ft_memalloc(sizeof(t_filler));
	
	// while (TRUE)
	// {
	// 	ft_putstr("2 2");
	// }
	return (0);
}