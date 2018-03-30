/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:13:58 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/18 20:53:58 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		n_digits(intmax_t n)
{
	int	r;

	r = 0;
	if (n < 0)
	{
		r++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		r++;
		n /= 10;
	}
	return (r);
}

char	*ft_itoa(intmax_t n)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = n_digits(n);
	s = ft_strnew(len);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		i = 1;
		s[0] = '-';
	}
	while (--len >= i)
	{
		s[len] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}
