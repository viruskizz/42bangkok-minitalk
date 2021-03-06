/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:05:52 by araiva            #+#    #+#             */
/*   Updated: 2022/04/03 18:05:53 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include "utils.h"

void	handler(int signum, siginfo_t *info, void *context);

t_talk	g_t;

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	ft_putstr_fd("SERVER: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &action, NULL);
	sigaction (SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	char	c;

	(void)info;
	(void)context;
	if (signum == SIGUSR2)
		g_t.byte += my_bitv(LBYTE - g_t.cidx - 1);
	g_t.cidx++;
	if (g_t.cidx == LBYTE)
	{
		c = (char) g_t.byte;
		write(1, &c, 1);
		g_t.cidx = 0;
		g_t.byte = 0;
	}
	if (signum == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else
		kill(info->si_pid, SIGUSR2);
}
