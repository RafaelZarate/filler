/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:14:45 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 14:52:55 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*p;
	char	*p2;

	i = 0;
	p = (char *)dst;
	p2 = (char *)src;
	if (p < p2)
	{
		while (i < len)
		{
			p[i] = p2[i];
			i++;
		}
	}
	else
	{
		while (len--)
			p[len] = p2[len];
	}
	return (dst);
}
