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
	pid_t	pid;
	struct sigaction	action;
	char	*str;

	if (argc < 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	printf("ID: %d\n", pid);
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &action, NULL);
	sigaction (SIGUSR2, &action, NULL);
	if (pid > 0)
	{
		while (*str)
			send_binary(pid, *str++);
	}
	while(1)
		pause();
	return (0);
}

void	send_binary(int pid, char c)
{
	int		i;

	i = LBYTE - 1;
	while (i >= 0)
	{
		if (!(c & (1 << i--)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	int		bit;
	char	c;

	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	g_t.byte += bit * my_bitv(LBYTE - g_t.cidx - 1);
	g_t.cidx++;
	if (g_t.cidx == LBYTE)
	{
		c = (char) g_t.byte;
		write(1, &c, 1);
		g_t.cidx = 0;
		g_t.byte = 0;
	}
}