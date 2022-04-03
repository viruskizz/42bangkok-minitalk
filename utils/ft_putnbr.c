/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:06:54 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/24 22:06:56 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static	int		my_write_nbr(int n);

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n == 0)
		ft_putchar('0');
	else if (n < 0)
	{
		ft_putchar('-');
		my_write_nbr(n * -1);
	}
	else
		my_write_nbr(n);
}

static	int	my_write_nbr(int n)
{
	char	c;

	if (n == 0)
		return (0);
	else
	{
		my_write_nbr(n / 10);
		c = (n % 10) + '0';
		ft_putchar(c);
	}
	return (0);
}
