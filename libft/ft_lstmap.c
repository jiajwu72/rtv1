/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:51:25 by klin              #+#    #+#             */
/*   Updated: 2017/11/15 14:20:05 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list_header;
	t_list		*list;

	if (!lst)
		return (NULL);
	list_header = f(lst);
	list = list_header;
	if (!list_header)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		list->next = f(lst);
		if (!list->next)
			return (NULL);
		list = list->next;
	}
	return (list_header);
}
