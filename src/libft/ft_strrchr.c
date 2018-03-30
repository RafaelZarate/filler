/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:58:44 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/19 20:20:16 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		n;
	char	*p;

	i = 0;
	p = NULL;
	n = ft_strlen(s);
	if (c == '\0')
	{
		p = (char *)&s[n];
	}
	while (i < n)
	{
		if (s[i] == c)
			p = (char *)&s[i];
		i++;
	}
	return (p);
}
