/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 23:13:27 by rzarate           #+#    #+#             */
/*   Updated: 2018/03/18 20:59:07 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*uitoa_base(uintmax_t n, unsigned int base)
{
	uintmax_t	i;
	size_t		len;
	char		*result;
	char		*str;

	i = n;
	len = 1;
	str = "0123456789abcdef";
	while ((i /= base))
		len++;
	result = ft_strnew(len);
	i = n;
	result[--len] = str[i % base];
	while ((i /= base))
		result[--len] = str[i % base];
	return (result);
}
