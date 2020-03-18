
#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{

	int i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

int main(void)
{




	ft_putstr_fd("\x1b[H\x1b[2J", 0);
	return (0);
}
