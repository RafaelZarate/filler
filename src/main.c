/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:58:01 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/01 15:55:39 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int	main(void)
{
	t_filler	*game;
	// int			y = -1;
	// int	x;

	game = (t_filler *)ft_memalloc(sizeof(t_filler));
	initialize_game(game);
	while (TRUE)
	{
		get_turn_data(game);
		// printf("Player #: %d, player char: %d\n", game->player->my_n, game->player->my_c);
		// while (++y < game->board->height)
		// 	printf("%s\n", game->board->map[y]);
		// y = -1;
		// while (++y < game->board->height)
		// {
		// 	x = -1;
		// 	while (++x < game->board->width)
		// 		printf("%d", game->board->heatmap[y][x]);
		// 	printf("\n");
		// }
		// y = -1;
		// while (++y < game->piece->height)
		// 	printf("%s\n", game->piece->map[y]);
		if (!make_move(game))
			break ;
	}
	finalize_game(game);
	return (0);
}
