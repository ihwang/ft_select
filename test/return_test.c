/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 15:16:32 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 16:17:15 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

int main(void)
{
	int fd;
	char *str;

	fd = open(ttyname(0), O_RDWR);
	str = ttyname(0);
	ft_putstr_fd("abcd", fd);
	return (0);
}
