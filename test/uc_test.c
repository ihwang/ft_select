/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uc_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:37:20 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 14:38:27 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>

int main(void)
{
	char *str;

	tgetent(NULL, getenv("TERM"));
	str = tgetstr("uc", NULL);
	tputs(str, 1, putchar);

	return (0);
}
