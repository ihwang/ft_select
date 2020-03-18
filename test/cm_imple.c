/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_imple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:38:00 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 16:44:05 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

void	cursor_move(char *str, int x, int y)
{
	tputs(tgoto(str, x, y), 1, putchar);
}

int main(int ac, char **av)
{
	int	i;
	char *str;

	i = 0;
	tgetent(NULL, getenv("TERM"));
	str = tgetstr("cm", NULL);
	while (++i < ac)
	{
		cursor_move(str, 0, i + 1);
		ft_putstr_fd(av[i], 1);
	}
	return (0);
}
