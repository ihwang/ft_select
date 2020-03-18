/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_cc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 23:33:50 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/13 23:34:47 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct termios old_settings;
int main()
{
    struct termios new_settings;
    int vdisable;
    char buf[255];

    if ((vdisable = fpathconf(0, _PC_VDISABLE)) < 0)
    {
        perror("error ");
        exit(0);
    }

    tcgetattr(0, &new_settings);

    old_settings = new_settings;
    new_settings.c_lflag |= ICANON;
    new_settings.c_cc[VSUSP] = vdisable;

    tcsetattr(0, TCSAFLUSH, &new_settings);
    memset(buf, 0x00, 255);
    read(0, buf, 255);
    printf("%s\n", buf);

    tcsetattr(0, TCSAFLUSH, &old_settings);
    exit(0);
}
