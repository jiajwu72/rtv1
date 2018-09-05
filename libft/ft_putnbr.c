/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:23:23 by klin              #+#    #+#             */
/*   Updated: 2017/11/14 14:57:18 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;
	int				size;

	size = 1;
	if (n < 0)
		ft_putchar('-');
	nb = ABS(n);
	while ((nb / 10) > 0)
	{
		nb /= 10;
		size *= 10;
	}
	nb = ABS(n);
	while (size >= 1)
	{
		ft_putchar(nb / size + '0');
		nb %= size;
		size /= 10;
	}
}
