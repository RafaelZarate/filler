/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:58:01 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/30 08:28:48 by rzarate          ###   ########.fr       */
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
		ft_putstr("2 2\n");
	}
	
	fclose(game->fp);
	return (0);
}