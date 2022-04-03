/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:06:01 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/22 13:12:25 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nb)
{
	int	prefix;
	int	number;

	number = 0;
	if (*nb == '\0' || *nb == '\e')
		return (0);
	while (*nb <= 32)
		nb++;
	if (*nb == '-')
		prefix = -1;
	else
		prefix = 1;
	if (*nb == '-' || *nb == '+')
		nb++;
	while (ft_isdigit(*nb))
		number = (number * 10) + (*nb++ - '0');
	return (prefix * number);
}
