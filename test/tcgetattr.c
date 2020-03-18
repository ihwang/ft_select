/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcgetattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:29:04 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/17 18:16:23 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>

#define UP 0x415B1B
#define DOWN 14073365508891
#define LEFT 1407333656399963
#define RIGHT 140733365573327

typedef struct termios t_term;

int main(void)
{
	char 	buf[7];
	t_term	term;
	t_term	oldset;
	int		fd;

	//fd = open(ttyname(0), O_RDWR | O_NONBLOCK);
	fd = 0;


	tcgetattr(fd, &term);
	oldset = term;
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_oflag &= ~OPOST;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;

	tcsetattr(fd, TCSANOW, &term);

	bzero(buf, sizeof(buf));
	read(0, buf, 7);

	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'A')
		printf("UP\n");
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'D')
		printf("LEFT\n");
//	else if (buf == RIGHT)
//		printf("RIGHT\n");
//	else if (buf == DOWN)
//		printf("DOWN \n");

	printf("%s\n", buf);
	tcsetattr(0, TCSANOW, &oldset);
	return (0);
}
