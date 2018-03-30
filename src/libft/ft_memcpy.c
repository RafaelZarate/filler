/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:56:36 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/21 12:38:53 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p;
	char	*p2;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	p = (char *)dst;
	p2 = (char *)src;
	while (i < n)
	{
		p[i] = p2[i];
		i++;
	}
	return (dst);
}
