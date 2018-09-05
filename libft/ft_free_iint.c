/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_iint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:48:47 by jwu               #+#    #+#             */
/*   Updated: 2018/01/08 17:49:10 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_free_iint(int ***s)
{
	size_t	w;
	size_t	i;
	int		**t;

	t = *s;
	i = 0;
	w = ft_iintlen(t);
	while (i < w)
	{
		free(t[i]);
		i++;
	}
	free(t);
}
