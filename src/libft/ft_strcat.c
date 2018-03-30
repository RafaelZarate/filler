/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:32:24 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/19 12:43:13 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(s1);
	while (s2[i])
	{
		s1[i + len] = s2[i];
		i++;
	}
	s1[i + len] = '\0';
	return (s1);
}
