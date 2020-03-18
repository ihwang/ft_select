/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 03:09:34 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 03:11:10 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <term.h>
#include <stdlib.h>

int main(void)
{
	char *str;

	tgetent(NULL, getenv("TERM"));
	str = tgetstr("me", NULL);
	tputs(str, 1, putchar);

	return (0);
}
