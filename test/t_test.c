/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:19:30 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/15 19:24:06 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>

void	a(void)
{
	char buf[1024];
	char *str;

	printf("%d\n", tgetent(buf, getenv("TERM")));
	str = tgetstr("cl", NULL);
    fputs(str, stdout);
}

int main(void)
{
	a();
	printf("HI\n");
	return (0);
}

