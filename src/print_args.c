/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:43:13 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/19 17:23:28 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	not_enough_space(void)
{
	ft_putstr_fd(CL, 0);
	ft_putstr_fd(ME, 0);
	ft_putstr_fd("Not enough space", 2);
}

void		print_args(int x, int y)
{
	int		i;
	size_t	max;

	i = -1;
	max = 0;
	ft_putstr_fd(CL, 0);
	while (++i < g_t.ac)
	{
		max = max > ft_strlen(g_t.av[i]) + x ? max : ft_strlen(g_t.av[i]) + x;
		ft_putstr_fd(tgoto(CM, x, ++y), 0);
		i == g_t.curr ? ft_putstr_fd(US, 0) : ft_putstr_fd(UE, 0);
		is_selected(i) ? ft_putstr_fd(SO, 0) : ft_putstr_fd(SE, 0);
		ft_putstr_fd(g_t.av[i], 0);
		if (y == ROW - 1)
		{
			y = -1;
			x = max + 3;
		}
	}
	if ((int)max > COL)
		not_enough_space();
}

