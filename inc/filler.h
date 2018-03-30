/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 03:57:11 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/29 06:44:18 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../src/libft/libft.h"
#include <limits.h>

/*
**	STRUCTURES
*/

typedef	struct s_board
{
	int		width;
	int		height;
	int		center;
	int		center_coords[2];
	char	**board;
}				t_board;

typedef	struct	s_piece
{
	int	width;
	int	height;
	int	size;
	int	*coords;
}				t_piece;

typedef	struct	s_filler
{
	int		player;
	t_board	*board;
	t_piece	*piece;
}				t_filler;

/*
**	MACROS 
*/

# define TRUE 1
# define FALSE 0


#endif // !1