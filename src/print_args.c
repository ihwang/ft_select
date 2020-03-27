/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:43:13 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/27 17:18:07 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	color_print(int i)
{
	t_stat	buf;

	if ((lstat(g_t.av[i], &buf)) == 0)
	{
		ft_isext(g_t.av[i], ".c") ? ft_putstr_fd(MGTA, 0) : 0;
		if (S_ISBLK(buf.st_mode))
			ft_putstr_fd(BLUE, 0);
		else if (S_ISCHR(buf.st_mode))
			ft_putstr_fd(GREN, 0);
		else if (S_ISDIR(buf.st_mode))
			ft_putstr_fd(CYAN, 0);
		else if (S_ISLNK(buf.st_mode))
			ft_putstr_fd(RED, 0);
		else if (S_ISSOCK(buf.st_mode))
			ft_putstr_fd(YELW, 0);
		else
			ft_putstr_fd(BOLD, 0);
	}
	ft_putstr_fd(g_t.av[i], 0);
	ft_putstr_fd(INIT, 0);
}

static void	not_enough_space(void)
{
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_putstr_fd(tgetstr("me", NULL), 0);
	ft_putstr_fd("Not enough space", 2);
}

void		print_args(int x, int y)
{
	int		i;
	size_t	max;

	i = -1;
	max = 0;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	while (++i < g_t.ac)
	{
		max = max > ft_strlen(g_t.av[i]) + x ? max : ft_strlen(g_t.av[i]) + x;
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), x, ++y), 0);
		i == g_t.curr ? ft_putstr_fd(tgetstr("us", NULL), 0) :
			ft_putstr_fd(tgetstr("ue", NULL), 0);
		is_selected(i) ? ft_putstr_fd(tgetstr("so", NULL), 0) :
			ft_putstr_fd(tgetstr("se", NULL), 0);
		color_print(i);
		if (y == tgetnum("li") - 1)
		{
			y = -1;
			x = max + 3;
		}
	}
	if ((int)max > tgetnum("co"))
		not_enough_space();
}
