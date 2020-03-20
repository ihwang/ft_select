/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 16:48:44 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/20 23:35:48 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ift_select.h"

void		tstp_handler(int a)
{
	t_term	term;
	char	cc[2];

	tcgetattr(0, &term);
	term.c_lflag |= (ICANON | ECHO);
	ft_strcpy(cc, term.c_cc[VSUSP]);
	tcsetattr(0, TCSANOW, &term);
	ioctl(0, TIOCSTI, cc);
}

void		cont_handler(int a)
{
	t_term term;
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &term);
	
}

void		sig_set(void)
{
	signal(SIGINT, esc_key);
	signal(SIGTSTP, stop);
	signal(SIGCONT, cont);
}

