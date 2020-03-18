/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nd_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 00:52:23 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 00:53:14 by ihwang           ###   ########.fr       */
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
	str = tgetstr("nd", NULL);
	tputs(str, 1, putchar);

	return (0);
}
