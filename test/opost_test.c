/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opost_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 02:51:39 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 02:55:59 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>

int main(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_oflag &= ~OPOST;
	tcsetattr(0, TCSANOW, &term);

	return (0);
}
