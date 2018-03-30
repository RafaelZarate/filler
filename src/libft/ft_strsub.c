/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 00:25:37 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 02:02:33 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	i = -1;
	r = ft_strnew(len);
	if (!r || !s)
		return (NULL);
	while (++i < len)
		r[i] = s[start++];
	r[len] = '\0';
	return (r);
}
