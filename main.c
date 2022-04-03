#include "minitalk.h"
#include "utils.h"
#include <stdio.h>

int main(int argc, char *argv[])
{

	if (argc < 2)
	{
		printf("NEED 2 argc: pid and text\n");
		exit(0);
	}
	char	*bit = "01111001";
	int 	byte;
	int 	i;

	i = 0;
	byte = 0;
	while (i < 8)
	{
		printf("%d, %d:%d\n", LBYTE - i - 1, (bit[i] - '0'), my_bitv(LBYTE - i - 1));
		byte += (bit[i] - '0') * my_bitv(LBYTE - i - 1);
		i++;
	}
	printf("\n01100001 = BYTE: %d\n", byte);
	return 0;
}
