/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 00:53:22 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 16:09:58 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*r;

	if (!s)
		return (NULL);
	i = -1;
	len = (int)ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
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
