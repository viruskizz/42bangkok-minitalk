#include "minitalk.h"
#include "libs/libft.h"

void  SIGINT_handler(int);
void  SIGQUIT_handler(int);

t_talk	talk;

void	handler(int signum, siginfo_t *info, void *context)
{
	int		bit;

	if (signum == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	if (signum == SIGUSR2)
	{
		if (!talk.byte)
			talk.byte = 2;
		else
			talk.byte *= 2;
	}
	talk.index++;
	printf("%d[%d] , \n", bit, talk.byte);
	ft_putnbr_fd(bit, 1);
	if (talk.index == LBYTE)
	{
		// ft_putchar_fd('\t');
		// ft_putnbr_fd(talk.byte, 1);
		// ft_putchar_fd(talk.byte, 1);
		talk.index = 0;
		talk.byte = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t 				pid;
	struct sigaction	action;

	if (!pid)
	{
		talk.index = 0;
		talk.str = ft_calloc(sizeof(char), 1);
		talk.str[0] = 0;
		talk.byte = 0;
	}
	pid = getpid();
	if (signal(SIGINT, SIGINT_handler) == SIG_ERR) {
		exit(0);
	}
	if (signal(SIGQUIT, SIGQUIT_handler) == SIG_ERR) {
		exit(0);
	}
	printf("Server [%d]: \n", pid);
	// action.sa_handler = handler;
	action.sa_sigaction = handler;
	// action.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &action, NULL);
	sigaction (SIGUSR2, &action, NULL);
	// signal(SIGUSR1, handler);
	// signal(SIGUSR2, handler);
	while(1)
		pause();
	return (0);
}

void  SIGINT_handler(int sig)
{
	signal(sig, SIG_IGN);
	printf("From SIGINT: just got a %d (SIGINT ^C) signal\n", sig);
	signal(sig, SIGINT_handler);
}

void  SIGQUIT_handler(int sig)
{
	signal(sig, SIG_IGN);
	printf("From SIGQUIT: just got a %d (SIGQUIT ^\\) signal and is about to quit\n", sig);
	exit(3);
}