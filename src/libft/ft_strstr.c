/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:24:06 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 02:54:24 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_test(const char *n, const char *h, int i, int i2)
{
	int test;

	test = 1;
	while (n[i2])
	{
		if (h[i] != n[i2])
			test = 0;
		i++;
		i2++;
	}
	return (test);
}

char		*ft_strstr(const char *h, const char *n)
{
	int i;
	int i2;

	i = 0;
	if (!n[i])
		return ((char *)h);
	while (i < ((int)ft_strlen(h) - (int)ft_strlen(n) + 1))
	{
		i2 = 0;
		if (h[i] == n[i2])
			if (ft_check_test(n, h, i, i2))
				return ((char *)&h[i]);
		i++;
	}
	return (NULL);
}
