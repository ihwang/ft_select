/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:52:55 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/19 01:08:33 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		esc_key(int opt, t_t *t)
{
	t ? tcsetattr(0, TCSANOW, &t->o_set) : 0;
	t ? free(t->sel) : 0;
	ft_putstr_fd(VE, 0);
	ft_putstr_fd(CL, 0);
	ft_putstr_fd(ME, 0);
	exit(opt);
}

static void	init(t_t *t, int ac, char **av)
{
	t_term	n_set;

	tcgetattr(0, &t->o_set);
	n_set = t->o_set;
	n_set.c_lflag &= ~(ICANON | ECHO);
	n_set.c_cc[VMIN] = 1;
	n_set.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &n_set);
	t->ac = ac - 1;
	t->av = av + 1;
	t->curr = 0;
	t->sel = (int*)malloc(sizeof(int) * t->ac);
	ft_bzero(t->sel, sizeof(int) * t->ac);
	//t->col = ac % ROW ? (ac / ROW) + 1 : ac / ROW;
	//get_maxcol
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
	if (t->curr - ROW < 0)
		t->curr = 0;
	else
		t->curr = t->curr - ROW;
}

void		right_key(t_t *t)
{
	if (t->curr + ROW >= t->ac)
		t->curr = t->ac - 1;
	else
		t->curr = t->curr + ROW;
}

void		space_key(t_t *t, int opt)
{
	int		i;
	int		cmp;

	i = -1;
	cmp = t->curr ? t->curr : t->ac;
	while (t->sel[++i])
	{
		if (t->sel[i] == cmp)
		{
			i--;
			while (t->sel[++i])
				t->sel[i] = t->sel[i + 1];
			opt == NEXT ? down_key(t) : 0;
			return ;
		}
	}
	i = -1;
	while (t->sel[++i])
		NULL;
	t->sel[i] = cmp;
	opt == NEXT ? down_key(t) : 0;
}

int			is_selected(t_t *t, int i)
{
	int		j;
	int		cmp;

	j = -1;
	cmp = i ? i : t->ac;
	while (t->sel[++j])
		if (t->sel[j] == cmp)
			return (1);
	return (0);
}

void		enter_key(t_t *t)
{
	int		i;

	t ? tcsetattr(0, TCSANOW, &t->o_set) : 0;
	t ? free(t->sel) : 0;
	ft_putstr_fd(VE, 0);
	ft_putstr_fd(CL, 0);
	ft_putstr_fd(ME, 0);
	i = -1;
	while (t->av[++i])
		if (is_selected(t, i))
		{
			ft_putstr_fd(t->av[i], 1);
			ft_putstr_fd(" ", 1);
		}
	exit(0);
}

void		bs_del_key(t_t *t)
{
	int		i;
	int		j;

	t->ac == 1 ? esc_key(0, t) : 0;
	i = -1;
	while (t->av[++i])
	{
		if (i == t->curr)
		{
			if (is_selected(t, i))
				space_key(t, STAY);
			j = -1;
			while (t->sel[++j])
				if (t->sel[j] > i)
					t->sel[j]--;
			i--;
			while (t->av[++i])
				t->av[i] = t->av[i + 1];
			t->ac--;
			t->curr == t->ac ? t->curr-- : 0;
			return ;
		}
	}
}

void		parse_key(t_t *t)
{
	if (ISESC(t->input))
		esc_key(0, t);
	else if (ISUP(t->input))
		up_key(t);
	else if (ISDW(t->input))
		down_key(t);
	else if (ISLE(t->input))
		left_key(t);
	else if (ISRT(t->input))
		right_key(t);
	else if (ISBS(t->input) || ISDE(t->input))
		bs_del_key(t);
	else if (ISSP(t->input))
		space_key(t, NEXT);
	else if (ISEN(t->input))
		enter_key(t);
}
void		print_args(t_t *t, int x, int y)
{
	int		i;
	size_t	max;

	i = -1;
	max = 0;
	ft_putstr_fd(CL, 0);
	while (++i < t->ac)
	{
		max = max > ft_strlen(t->av[i]) + x ? max : ft_strlen(t->av[i]) + x;
		ft_putstr_fd(tgoto(CM, x, ++y), 0);
		i == t->curr ? ft_putstr_fd(US, 0) : ft_putstr_fd(UE, 0);
		is_selected(t, i) ? ft_putstr_fd(SO, 0) : ft_putstr_fd(SE, 0);
		ft_putstr_fd(t->av[i], 0);
		if (y == ROW - 1)
		{
			y = -1;
			x = max + 3;
		}
	}
}

int			main(int ac, char **av)
{
	t_t		t;

	if (ac == 1)
		esc_key(0, NULL);//hint: No arguments
	if (0 > (tgetent(NULL, getenv("TERM"))))
		esc_key(0, NULL);//hint: No environment variable 'TERM'
	init(&t, ac, av);
	while (1)
	{
		print_args(&t, 0, -1);
		ft_bzero(t.input, sizeof(t.input));
		read(0, t.input, sizeof(t.input));
		parse_key(&t);
	}
	printf("%d\n", ROW);
	return (0);
}
