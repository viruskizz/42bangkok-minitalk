/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomsa <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:48:00 by tsomsa            #+#    #+#             */
/*   Updated: 2022/02/24 21:48:03 by tsomsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}
