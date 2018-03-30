/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:55:43 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 13:51:01 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	if (!n[i])
		return ((char *)h);
	while ((h[i] != '\0') && (i < len))
	{
		y = i;
		x = 0;
		while ((h[y] == n[x]) && (y <= len))
		{
			y++;
			x++;
			if (n[x] == '\0')
				return ((char *)&h[i]);
		}
		i++;
	}
	return (NULL);
}
