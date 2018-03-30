/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:57:56 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 16:32:34 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	int		i;
	int		len;
	char	*r;

	if (!s)
		return (NULL);
	i = -1;
	len = (int)ft_strlen(s);
	while (s[len - 1] == c || s[len - 1] == c || s[len - 1] == c)
		len--;
	while (s[++i] == c || s[i] == c || s[i] == c)
		len--;
	if (len < 0)
		len = 0;
	r = ft_strnew(len);
	if (!r)
		return (NULL);
	s += i;
	i = -1;
	while (++i < len)
	{
		r[i] = *s++;
	}
	r[i] = '\0';
	return (r);
}
