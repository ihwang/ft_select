/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:48:44 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/27 17:18:13 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	tstp_handler(int a)
{
	char	cc[2];

	(void)a;
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	ft_putstr_fd(tgetstr("me", NULL), 0);
	cc[0] = g_t.o_set.c_cc[VSUSP];
	cc[1] = '\0';
	tcsetattr(0, TCSANOW, &g_t.o_set);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cc);
}

static void	cont_handler(int a)
{
	t_term n_set;

	(void)a;
	if (0 > (tgetent(NULL, getenv("TERM"))))
		esc_key(NOENV);
	n_set = g_t.o_set;
	n_set.c_lflag &= ~(ICANON | ECHO);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
	tcsetattr(0, TCSANOW, &n_set);
	sig_set();
	print_args(0, -1);
	ft_bzero(g_t.input, sizeof(g_t.input));
}

static void	resize(int a)
{
	(void)a;
	if (0 > (tgetent(NULL, getenv("TERM"))))
		esc_key(NOENV);
	print_args(0, -1);
}

void		sig_set(void)
{
	signal(SIGINT, esc_key);
	signal(SIGQUIT, esc_key);
	signal(SIGWINCH, resize);
	signal(SIGTSTP, tstp_handler);
	signal(SIGCONT, cont_handler);
}
