/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgoto_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:55:04 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/15 21:06:59 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

int main(void)
{
	char *str;
	char *foo;

	tgetent(NULL, getenv("TERM"));
	str = tgetstr("cl", NULL);
	foo = tgoto(str, 10, 5);
	ft_putstr_fd(foo, 0);

	return (0);
}
