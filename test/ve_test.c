/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ve_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 03:03:33 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 03:04:49 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *str;

	tgetent(NULL, getenv("TERM"));
	str = tgetstr("ve", NULL);
	tputs(str, 1, putchar);

	return (0);
}
