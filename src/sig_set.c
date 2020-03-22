/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:48:44 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/21 22:23:24 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void		tstp_handler(int a)
{
	char	cc[2];

	(void)a;
	tcsetattr(0, TCSANOW, &g_t.o_set);
	ft_putstr_fd(VE, 0);
	ft_putstr_fd(ME, 0);
	ft_addchar(cc, g_t.o_set.c_cc[VSUSP]);
	ioctl(0, TIOCSTI, cc);
}

void		cont_handler(int a)
{
	t_term n_set;

	(void)a;
	n_set = g_t.o_set;
	n_set.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &n_set);
	
}

void		sig_set(void)
{
	signal(SIGINT, esc_key);
	signal(SIGTSTP, tstp_handler);
	signal(SIGCONT, cont_handler);
}

