/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 00:37:54 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 00:52:08 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	int i;

	i = -1;
	while (str[++i])
	{
		write(fd, &str[i], 1);
	}
}

int main(void)
{
	char *str;

	tgetent(NULL, getenv("TERM"));
	str = tgetstr("le", NULL);
	ft_putstr_fd(str, 0);


	return (0);
}
