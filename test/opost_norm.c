/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opost_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 02:57:02 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/16 02:58:04 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>

int main(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_oflag |= OPOST;
	tcsetattr(0, TCSANOW, &term);

	return (0);
}
