/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 23:56:09 by rzarate           #+#    #+#             */
/*   Updated: 2018/02/23 00:10:02 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	if (!new)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!new->next)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
