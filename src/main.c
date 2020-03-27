/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:52:55 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/27 16:35:16 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	init(int ac, char **av)
{
	t_term	n_set;

	tcgetattr(0, &g_t.o_set);
	n_set = g_t.o_set;
	n_set.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &n_set);
	g_t.ac = ac - 1;
	g_t.av = av + 1;
	g_t.curr = 0;
	g_t.sel = (int*)malloc(sizeof(int) * (g_t.ac + 1));
	ft_bzero(g_t.sel, sizeof(int) * (g_t.ac + 1));
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
	sig_set();
}

int			main(int ac, char **av)
{
	if (ac == 1)
		esc_key(NOARG);
	if (0 > (tgetent(NULL, getenv("TERM"))))
		esc_key(NOENV);
	init(ac, av);
	while (1)
	{
		print_args(0, -1);
		ft_bzero(g_t.input, sizeof(g_t.input));
		read(0, g_t.input, sizeof(g_t.input));
		parse_key();
	}
	return (0);
}
