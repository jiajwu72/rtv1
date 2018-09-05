/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:18:53 by klin              #+#    #+#             */
/*   Updated: 2017/11/24 13:49:03 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **list, t_list *new)
{
	t_list		*tmp;

	if (!(*list) || (*list)->content == NULL)
		(*list) = new;
	else
	{
		tmp = (*list);
		while (tmp->next != NULL && (tmp->next)->content != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
