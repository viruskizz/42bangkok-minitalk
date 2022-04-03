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

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	printf("Server [%d]: \n", pid);
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
	int		bit;

	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	g_t.byte += bit * my_bitv(LBYTE - g_t.cidx - 1);
	g_t.cidx++;
	if (g_t.cidx == LBYTE)
	{
		ft_putchar(g_t.byte);
		g_t.cidx = 0;
		g_t.byte = 0;
	}
	// if (signum == SIGUSR1)
	// 	kill(info->si_pid, SIGUSR1);
	// else
	// 	kill(info->si_pid, SIGUSR2);
}
