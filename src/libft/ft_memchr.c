/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:51:28 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/20 12:54:39 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*p;
	size_t		i;

	i = 0;
	p = (const char *)s;
	while (i < n)
	{
		if (p[i] == (char)c)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
