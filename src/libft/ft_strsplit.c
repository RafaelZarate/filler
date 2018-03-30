/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:51:39 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 02:11:44 by rzarate          ###   ########.fr       */
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

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		i2;
	int		y;
	char	**r;
	char	*ns;

	i = -1;
	y = 0;
	ns = ft_strtrimc(s, c);
	r = (char **)malloc(sizeof(char *) * (ft_countwords(ns, c) + 1));
	if (!r || !ns)
		return (NULL);
	while (ns[++i])
	{
		if (ft_is_valid(i, ns, c))
		{
			i2 = i;
			while (ns[i2] && ns[i2] != c)
				i2++;
			r[y] = ft_strsub(ns, i, i2 - i);
			y++;
		}
	}
	r[y] = NULL;
	return (r);
}
