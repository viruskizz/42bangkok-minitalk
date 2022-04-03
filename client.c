#include "minitalk.h"
#include "utils.h"

void	send_binary(int pid, char c);

int main(int argc, char *argv[])
{
	pid_t 	pid;
	char	*str;

	if (argc < 3)
	{
		printf("NEED 2 argc: pid and text\n");
		exit(0);
	}

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
	printf("\t %c:[%d]", c, c);
	while (i >= 0)
	{
		bit = (c & (1 << i));
		ft_putnbr(!bit);
		if (!bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(500);
	}
	printf("\n");
}