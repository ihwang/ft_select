/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 18:17:13 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/17 18:20:14 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr_fd(char *str, int fd)
{
	int i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

int main(void)
{
	int	fd;

	fd = open(ttyname(2), O_RDWR | O_NONBLOCK);
	ft_putstr_fd("abcd", fd);


	return (0);
}
