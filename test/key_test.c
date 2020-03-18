/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 00:11:44 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/18 00:15:14 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

int main(void)
{
	char buf[10];
	struct termios old;
	struct termios new;
	int i;

	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSANOW, &new);
	i = -1;
	bzero(buf, sizeof(buf));
	while (++i < 10)
		read(0, buf, sizeof(buf));
	tcsetattr(0, TCSANOW, &old);
	return (0);
}
