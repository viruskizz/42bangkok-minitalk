/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:02:55 by araiva            #+#    #+#             */
/*   Updated: 2022/04/03 18:02:56 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include "utils.h"

void	send_binary(int pid, char c);
void	handler(int signum, siginfo_t *info, void *context);

t_talk	g_t;

int	main(int argc, char *argv[])
{
	struct sigaction	action;
	pid_t				pid;
	char				*str;

	if (argc < 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	g_t.byte = 0;
	g_t.cidx = 0;
	ft_putstr_fd("ID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &action, NULL);
	sigaction (SIGUSR2, &action, NULL);
	if (pid > 0)
		while (*str)
			send_binary(pid, *str++);
	return (0);
}

void	send_binary(int pid, char c)
{
	int		i;

	i = 7;
	while (i >= 0)
	{
		if (!(c & (1 << i--)))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(1000);
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR1)
		write(2, "0", 1);
	else
		write(2, "1", 1);
	usleep(1000);
}
