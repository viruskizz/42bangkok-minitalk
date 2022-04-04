/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:41:23 by araiva            #+#    #+#             */
/*   Updated: 2022/04/04 19:41:25 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>

void	handler(int signum, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	printf("SERVER: %d\n", pid);
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &action, NULL);
	while (1)
		pause();
	return (0);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}