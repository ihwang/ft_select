/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   us_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 03:07:09 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 03:08:17 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *str;

	tgetent(NULL, getenv("TERM"));
	str = tgetstr("us", NULL);
	tputs(str, 1, putchar);

	return (0);
}
