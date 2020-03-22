/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:45:53 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/22 20:25:57 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int			is_selected(int i)
{
	int		j;
	int		cmp;

	j = -1;
	cmp = i ? i : g_t.ac;
	while (g_t.sel[++j])
		if (g_t.sel[j] == cmp)
			return (1);
	return (0);
}

void		esc_key(int opt)
{
	if (opt == NOENV)
		ft_putstr_fd("No `TERM` environment variable\n", 2);
	else if (opt == NOARG)
		ft_putstr_fd("No arguments\n", 2);
	else
	{
		ft_putstr_fd(CL, 0);
		ft_putstr_fd(VE, 0);
		ft_putstr_fd(ME, 0);
		tcsetattr(0, TCSANOW, &g_t.o_set);
	}
	free(g_t.sel);
	exit(opt);
}

void		space_key(int opt)
{
	int		i;
	int		cmp;

	i = -1;
	cmp = g_t.curr ? g_t.curr : g_t.ac;
	while (g_t.sel[++i])
	{
		if (g_t.sel[i] == cmp)
		{
			i--;
			while (g_t.sel[++i])
				g_t.sel[i] = g_t.sel[i + 1];
			opt == NEXT ? down_key() : 0;
			return ;
		}
	}
	i = -1;
	while (g_t.sel[++i])
		NULL;
	g_t.sel[i] = cmp;
	opt == NEXT ? down_key() : 0;
}

void		enter_key(void)
{
	int		i;

	tcsetattr(0, TCSANOW, &g_t.o_set);
	free(g_t.sel);
	ft_putstr_fd(VE, 0);
	ft_putstr_fd(CL, 0);
	ft_putstr_fd(ME, 0);
	i = -1;
	while (g_t.av[++i])
		if (is_selected(i))
		{
			ft_putstr_fd(g_t.av[i], 1);
			ft_putstr_fd(" ", 1);
		}
	exit(0);
}

void		bs_del_key(void)
{
	int		i;

	g_t.ac == 1 ? esc_key(0) : 0;
	is_selected(g_t.curr) ? space_key(STAY) : 0;
	i = -1;
	while (g_t.sel[++i])
	{
		g_t.sel[i] > g_t.curr ? g_t.sel[i]-- : 0;
		g_t.sel[i] = !g_t.sel[i] ? g_t.ac - 1 : g_t.sel[i];
	}
	i = g_t.curr - 1;
	while (g_t.av[++i])
		g_t.av[i] = g_t.av[i + 1];
	g_t.ac--;
	g_t.curr == g_t.ac ? g_t.curr-- : 0;
}
