/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 02:43:47 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/27 17:17:47 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		down_key(void)
{
	if (g_t.curr == g_t.ac - 1)
		g_t.curr = 0;
	else
		g_t.curr++;
}

static void	up_key(void)
{
	if (g_t.curr == 0)
		g_t.curr = g_t.ac - 1;
	else
		g_t.curr--;
}

static void	left_key(void)
{
	if (g_t.curr - tgetnum("li") < 0)
		g_t.curr = 0;
	else
		g_t.curr = g_t.curr - tgetnum("li");
}

static void	right_key(void)
{
	if (g_t.curr + tgetnum("li") >= g_t.ac)
		g_t.curr = g_t.ac - 1;
	else
		g_t.curr = g_t.curr + tgetnum("li");
}

void		parse_key(void)
{
	if (g_t.input[0] == 27 && g_t.input[1] == '\0')
		esc_key(NORM);
	else if (g_t.input[0] == 27 && g_t.input[1] == 91 && g_t.input[2] == 'A')
		up_key();
	else if (g_t.input[0] == 27 && g_t.input[1] == 91 && g_t.input[2] == 'B')
		down_key();
	else if (g_t.input[0] == 27 && g_t.input[1] == 91 && g_t.input[2] == 'D')
		left_key();
	else if (g_t.input[0] == 27 && g_t.input[1] == 91 && g_t.input[2] == 'C')
		right_key();
	else if ((g_t.input[0] == 127 && g_t.input[1] == '\0') ||
		(g_t.input[0] == 27 && g_t.input[1] == 91 && g_t.input[2] == '3' &&
		g_t.input[3] == '~'))
		bs_del_key();
	else if (g_t.input[0] == ' ' && g_t.input[1] == '\0')
		space_key(NEXT);
	else if (g_t.input[0] == '\n' && g_t.input[1] == '\0')
		enter_key();
}
