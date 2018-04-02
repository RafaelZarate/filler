/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:51:39 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/02 10:33:27 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_is_valid(int i, char *s, char c)
{
	int r;

	r = 0;
	if (i == 0)
		r = 1;
	else if (i > 0)
	{
		if (s[i] != c && s[i - 1] == c)
			r = 1;
	}
	return (r);
}

char			**ft_strsplit(char *s, char c)
{
	int		i;
	int		i2;
	int		y;
	char	**r;

	i = -1;
	y = 0;
	r = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!r)
		return (NULL);
	while (s[++i])
	{
		if (ft_is_valid(i, s, c))
		{
			i2 = i;
			while (s[i2] && s[i2] != c)
				i2++;
			r[y] = ft_strsub(s, i, i2 - i);
			y++;
		}
	}
	r[y] = NULL;
	return (r);
}
