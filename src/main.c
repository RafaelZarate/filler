/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:58:01 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/02 11:37:23 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int	main(void)
{
	t_filler	*game;

	game = (t_filler *)ft_memalloc(sizeof(t_filler));
	initialize_game(game);
	while (TRUE)
	{
		get_turn_data(game);
		if (!make_move(game))
			break ;
	}
	finalize_game(game);
	return (0);
}
