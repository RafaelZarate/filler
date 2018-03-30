/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 00:37:12 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 15:17:02 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	r = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!r)
		return (NULL);
	ft_strcpy(r, s1);
	ft_strcat(r, s2);
	return (r);
}
