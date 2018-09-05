/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:59:21 by klin              #+#    #+#             */
/*   Updated: 2017/11/14 15:07:35 by klin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	unsigned int	size;

	size = 1;
	if (n < 0)
		ft_putchar_fd('-', fd);
	nb = ABS(n);
	while ((nb / 10) > 0)
	{
		nb /= 10;
		size *= 10;
	}
	nb = ABS(n);
	while (size >= 1)
	{
		ft_putchar_fd(nb / size + '0', fd);
		nb %= size;
		size /= 10;
	}
}
