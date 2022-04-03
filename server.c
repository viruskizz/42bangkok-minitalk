#include "minitalk.h"
#include "utils.h"

void	handler(int signum, siginfo_t *info, void *context);

t_talk	t;

int	main(int argc, char *argv[])
{
	pid_t 				pid;
	struct sigaction	action;

	pid = getpid();
	printf("Server [%d]: \n", pid);
	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &action, NULL);
	sigaction (SIGUSR2, &action, NULL);
	while(1)
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
	t.byte += bit * my_bitv(LBYTE - t.cidx - 1);
	t.cidx++;
	if (t.cidx == LBYTE)
	{
		ft_putchar(t.byte);
		t.cidx = 0;
		t.byte = 0;
	}
}
