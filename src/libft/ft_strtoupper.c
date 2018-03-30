/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 01:45:26 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/20 15:13:01 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtoupper(char **s)
{
	size_t	i;
	char	*tmp;
	char	*str;

	str = *s;
	tmp = ft_strnew(ft_strlen(str));
	i = -1;
	while (str[++i])
	{
		if (ft_islower(str[i]))
			tmp[i] = str[i] - 32;
		else
			tmp[i] = str[i];
	}
	free(*s);
	*s = tmp;
}
