/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 04:36:02 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/22 05:48:42 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countnums(char *s)
{
	int i;
	int r;

	r = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (ft_isdigit(s[i]))
		{
			r++;
			while (s[i] && ft_isdigit(s[i]))
				i++;
		}
	}
	return (r);
}
