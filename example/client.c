/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:41:31 by araiva            #+#    #+#             */
/*   Updated: 2022/04/04 19:41:32 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

static int	ft_isdigit(char c);
static int	ft_atoi(const char *nb);

int	main(int argc, char *argv[])
{
	pid_t				pid;
	char				*str;

	if (argc < 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (pid > 0)
	{
		while (*str++)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
			sleep(1);
		}
	}

	return (0);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_atoi(const char *nb)
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