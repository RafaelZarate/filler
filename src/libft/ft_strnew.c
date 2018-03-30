/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:23:32 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/20 13:05:19 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *p;

	p = (char *)malloc(sizeof(char) * size + 1);
	if (!p)
		return (NULL);
	ft_bzero(p, size + 1);
	return (p);
}
