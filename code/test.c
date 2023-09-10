#include <unistd.h>
#include <stdio.h>

void	showbit(unsigned char c)
{
	int	i;
	unsigned int	bit;

	i = 8;
	while (i--)
	{
		bit = (c >> i & 1) + 48; // ou '0'
		write(1, &bit, 1);
	}
}
void	showbit(unsigned char c)
{
	int	i = 8;
	while (i--)
		write(1, (c >> i & 1)) ? "1" : "0", 1);
}
// 01010101
// 00000000 010
// 00000000
//       01
//      010
// 00000000
// 00000001

void	showbit(unsigned char c)
{
	int	i = 8;
	while (i--)
	{
		printf("%d\n", (c >> i & 1));
	}
}

int	main(void)
{
	showbit('A');
	return (0);
}

10 = 010