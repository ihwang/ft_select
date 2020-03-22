/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:45:00 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/22 19:59:38 by ihwang           ###   ########.fr       */
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
	if (g_t.curr - ROW < 0)
		g_t.curr = 0;
	else
		g_t.curr = g_t.curr - ROW;
}

static void	right_key(void)
{
	if (g_t.curr + ROW >= g_t.ac)
		g_t.curr = g_t.ac - 1;
	else
		g_t.curr = g_t.curr + ROW;
}

void		parse_key(void)
{
	if (ISESC(g_t.input))
		esc_key(NORM);
	else if (ISUP(g_t.input))
		up_key();
	else if (ISDW(g_t.input))
		down_key();
	else if (ISLE(g_t.input))
		left_key();
	else if (ISRT(g_t.input))
		right_key();
	else if (ISBS(g_t.input) || ISDE(g_t.input))
		bs_del_key();
	else if (ISSP(g_t.input))
		space_key(NEXT);
	else if (ISEN(g_t.input))
		enter_key();
}
