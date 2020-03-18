/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ue_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:54:27 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 14:55:03 by ihwang           ###   ########.fr       */
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
	str = tgetstr("ue", NULL);
	tputs(str, 1, putchar);

	return (0);
}
