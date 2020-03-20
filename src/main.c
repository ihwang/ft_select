/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:52:55 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/20 23:31:28 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"


static void	init(int ac, char **av)
{
	t_term	n_set;

	tcgetattr(0, &g_t.o_set);
	n_set = g_t.o_set;
	n_set.c_lflag &= ~(ICANON | ECHO);
//	n_set.c_cc[VMIN] = 1;
//	n_set.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &n_set);
	g_t.ac = ac - 1;
	g_t.av = av + 1;
	g_t.curr = 0;
	g_t.sel = (int*)malloc(sizeof(int) * g_t.ac);
	ft_bzero(g_t.sel, sizeof(int) * g_t.ac);
	ft_putstr_fd(CL, 0);
	ft_putstr_fd(VI, 0);//Cursor disapear
	//sig_set();
}

int			main(int ac, char **av)
{
	if (ac == 1)
		esc_key(0);//hint: No arguments
	if (0 > (tgetent(NULL, getenv("TERM"))))
		esc_key(0);//hint: No environment variable 'TERM'
	init(ac, av);
	while (1)
	{
		print_args(0, -1);
		ft_bzero(g_t.input, sizeof(g_t.input));
		read(0, g_t.input, sizeof(g_t.input));
		parse_key();
	}
	printf("%d\n", ROW);
	return (0);
}
