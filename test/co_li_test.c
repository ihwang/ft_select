/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_li_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:42:18 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/15 21:46:00 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int co;
	int li;

	tgetent(NULL, getenv("TERM"));
	co = tgetnum("co");
	li = tgetnum("li");
	printf("co is %d\n", co);
	printf("li is %d\n", li);
	return (0);
}
