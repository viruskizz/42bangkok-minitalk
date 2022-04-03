/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:04:17 by araiva            #+#    #+#             */
/*   Updated: 2022/04/03 18:04:18 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include "utils.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*bit;
	int		byte;
	int		i;

	i = 0;
	byte = 0;
	bit = "01111001";
	if (argc < 2)
		exit(0);
	while (i < 8)
	{
		byte += (bit[i] - '0') * my_bitv(LBYTE - i - 1);
		i++;
	}
	printf("\n01100001 = BYTE: %d\n", byte);
	return (0);
}
// printf("%d:%d\n", (bit[i] - '0'), my_bitv(LBYTE - i - 1));