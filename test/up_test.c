/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 00:56:43 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 00:57:38 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *str;
	tgetent(NULL, getenv("TERM"));
	str = tgetstr("up", NULL);
	tputs(str, 1, putchar);

	return (0);
}
