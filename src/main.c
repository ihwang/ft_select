/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:52:55 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/18 03:06:27 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"




void		quit(int opt, t_t *t)
{
	t ? tcsetattr(0, TCSANOW, &t->o_set) : 0;
	ft_putstr_fd(VE, 0);
	ft_putstr_fd(CL, 0);
	exit(opt);
}

static void	init_sub(t_t *t)
{
	


}

static void	get_maxcol(t_t *t)
{
	int		i;

	i = -1;
	while (++i < t->ac)
	{
		ft_strlen(
				////////////////////////HERE

	}

}

static void	init(t_t *t, int ac, char **av)
{
	t_term	n_set;

	tcgetattr(0, &t->o_set);
	n_set = t->o_set;
	n_set.c_lflag &= ~(ICANON | ECHO);
	//n_set.c_oflag &= ~(OPOST);
	n_set.c_cc[VMIN] = 1;
	n_set.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &n_set);
	t->ac = ac - 1;
	t->av = av + 1;
	t->sel = ac - 1;
	t->curr = 0;
	t->col = ac % ROW ? (ac / ROW) + 1 : ac / ROW;
	get_maxcol
	ft_putstr_fd(CL, 0);
	ft_putstr_fd(VI, 0);//Cursor disapear
	//sig_set();
}

void		up_key(t_t *t)
{
	if (t->curr == 0)
		t->curr = t->ac - 1;
	else
		t->curr--;
}

void		down_key(t_t *t)
{
	if (t->curr == t->ac - 1)
		t->curr = 0;
	else
		t->curr++;
}

void		left_key(t_t *t)
{
	if (t->curr + ROW)

}

void		parse_key(t_t *t)
{
	if (ISESC(t->input))
		quit(0, t);
	else if (ISUP(t->input))
		up_key(t);
	else if (ISDW(t->input))
		down_key(t);
	else if (ISLE(t->input))
		left_key(t);
	else if (ISRT(t->input))
		printf("RIGHT\n");
	else if (ISBS(t->input) || ISDE(t->input))
		printf("BS OR DEL\n");
	else if (ISSP(t->input))
		printf("SPACE\n");

}

int			main(int ac, char **av)
{
	t_t		t;

	if (ac == 1)
		quit(0, NULL);//hint: No arguments
	if (0 > (tgetent(NULL, getenv("TERM"))))
		quit(0, NULL);//hint: No environment variable `TERM`
	init(&t, ac, av);
	while (1)
	{
		ft_bzero(t.input, sizeof(t.input));
		read(0, t.input, sizeof(t.input));
		parse_key(&t);
	}
	return (0);
}
