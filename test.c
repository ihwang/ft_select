/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 01:07:47 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/23 01:50:09 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdio.h>
#include <unistd.h>
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
	tgetent(NULL, getenv("TERM"));
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 0, 0), 0);

	ft_putstr_fd(tgetstr("dl", NULL), 0);
	return (0);
}
