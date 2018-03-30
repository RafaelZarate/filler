/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:54:36 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 01:35:15 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	i2;
	size_t	dst_s;
	size_t	src_s;

	dst_s = ft_strlen(dst);
	src_s = ft_strlen(src);
	i = dst_s;
	i2 = 0;
	if (s <= dst_s)
		return (src_s + s);
	while (src[i2] && i < (s - 1))
	{
		dst[i] = src[i2];
		i++;
		i2++;
	}
	dst[i] = '\0';
	return (dst_s + src_s);
}
