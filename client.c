#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "libs/libft.h"

void	send_binary(int pid, char c);

int main(int argc, char *argv[])
{
	pid_t 	pid;
	char	*str;

	if (argc < 3)
		exit(0);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	printf("ID: %d\n", pid);
	if (pid  > 0)
	{
		while (*str)
			send_binary(pid, *str++);
	}
	return 0;
}

void	send_binary(int pid, char c)
{
	int		i;
	int		bit;

	i = 7;
	while (i >= 0)
	{
		bit = !((c << i) & 0x80);
		ft_putnbr_fd(bit, 1);
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(1000 * 1000);
	}
	printf("\n");
}