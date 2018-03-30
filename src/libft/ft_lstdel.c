/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 01:13:49 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/22 01:31:27 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*d;
	t_list	*next;

	d = *alst;
	while (d)
	{
		next = d->next;
		ft_lstdelone(&d, del);
		d = next;
	}
	*alst = NULL;
}
