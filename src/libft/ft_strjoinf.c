/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:22:22 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/21 21:18:46 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char **s1, char **s2, int i)
{
	char	*r;

	if (!(*s1) || !(*s2))
		return (NULL);
	r = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2));
	if (!r)
		return (NULL);
	ft_strcpy(r, *s1);
	ft_strcat(r, *s2);
	if (i == 1)
		ft_strdel(s1);
	else if (i == 2)
		ft_strdel(s2);
	else if (i == 3)
	{
		ft_strdel(s1);
		ft_strdel(s2);
	}
	return (r);
}
