/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 14:07:51 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/23 14:18:36 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[999999];
	int	fd;

	printf("%s\n", ttyname(1));
	fd = open(ttyname(1), O_RDWR);

	bzero(buf, sizeof(buf));
	read(fd, buf, sizeof(buf));
	printf("%s\n", buf);


	return (0);
}
