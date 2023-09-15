#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// void	showbit(unsigned char c)
// {
// 	int	i;
// 	unsigned int	bit;

// 	i = 8;
// 	while (i--)
// 	{
// 		bit = (c >> i & 1) + 48; // ou '0'
// 		write(1, &bit, 1);
// 	}
// }
// void	showbit(unsigned char c)
// {
// 	int	i = 8;
// 	while (i--)
// 		write(1, (c >> i & 1)) ? "1" : "0", 1);
// }
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

#define t "OK"

int	main(void)
{
	char	*s;

	s = malloc (sizeof(char *) * 3);
	s[0] = 48;
	s[1] = 49;
	s[2] = 0;
	// free(&(s[0]));
	// free(&(s[1]));
	// free(&(s[2]));
	free(s);
	s = NULL;
	if (s)
		printf("%c\n", s[0]);
	return (0);
}

