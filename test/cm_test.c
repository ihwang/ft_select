/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cm_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:49:21 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/17 02:49:25 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>

# define COL (tgetnum("co"))
# define ROW (tgetnum("li"))

# define CL (tgetstr("cl", NULL))
# define CM (tgetstr("cm", NULL))
# define US (tgetstr("us", NULL))
# define UE (tgetstr("ue", NULL))

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

int		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (c);
}

int main(void)
{

	tgetent(NULL, getenv("TERM"));

	ft_putstr_fd(CL, 0);


	ft_putstr_fd(tgoto(CM, 0, 0), 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 0, 1), 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 0, 2), 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 5, 0), 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 5, 1), 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 5, 2), 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 10, 0), 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 10, 1), 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 10, 2), 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 0, 0), 0);
	ft_putstr_fd(US, 0);
	ft_putstr_fd("HI", 0);

	ft_putstr_fd(tgoto(CM, 0, 3), 0);

	return (0);
}
