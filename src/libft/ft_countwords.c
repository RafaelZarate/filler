/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:07:30 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/22 04:36:13 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char *s, char c)
{
	int i;
	int r;

	r = 1;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
		{
			r++;
			while (s[i] && s[i] == c)
				i++;
		}
		i++;
	}
	return (r);
}
