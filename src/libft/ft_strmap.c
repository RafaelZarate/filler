/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:54:32 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/21 22:04:08 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*p;

	i = 0;
	if (!s || !f)
		return (NULL);
	p = ft_strnew(ft_strlen(s));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = f(s[i]);
		i++;
	}
	return (p);
}
