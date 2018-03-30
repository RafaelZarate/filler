/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:28:40 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/20 22:12:09 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	i = 0;
	p = ft_strnew(ft_strlen(s1));
	if (!p || !s1)
		return (NULL);
	ft_strcpy(p, s1);
	return (p);
}
