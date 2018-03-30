/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:53:35 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 02:33:20 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(s1);
	while (i < n && s2[i])
	{
		s1[i + len] = s2[i];
		i++;
	}
	s1[i + len] = '\0';
	return (s1);
}
