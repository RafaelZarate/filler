/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 00:03:05 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/21 22:04:02 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	r = ft_strnew(ft_strlen(s));
	if (!r)
		return (NULL);
	while (s[i])
	{
		r[i] = f(i, s[i]);
		i++;
	}
	return (r);
}
