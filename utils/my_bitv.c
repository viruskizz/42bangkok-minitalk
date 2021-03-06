/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_bitv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:49:35 by araiva            #+#    #+#             */
/*   Updated: 2022/04/03 14:49:36 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_bitv(int pos)
{
	int		sum;

	sum = 1;
	if (pos == 0)
		return (sum);
	while (pos-- > 0)
		sum = sum * 2;
	return (sum);
}
