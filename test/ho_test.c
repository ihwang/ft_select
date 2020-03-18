/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ho_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 00:14:50 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 00:16:42 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <stdio.h>

int main(void)
{
	char *str;

	tgetent(NULL, getenv("TERM"));
	str = tgetstr("ho", NULL);
	tputs(str, 1, putchar);
	return (0);
}
