/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputs_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:15:04 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/15 21:21:08 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <term.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (c);
}

int main(void)
{
	char *str;
//	char *foo;

	tgetent(NULL, getenv("TERM"));
//	str = tgetstr("cm", NULL);

	str = tgetstr("cl", NULL);
//	foo = tgoto(str, 0, 0);

	tputs(str, 2, ft_putchar);

	return (0);
}




