/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 23:00:10 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/13 23:00:16 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <termios.h>
#include <string.h>

static struct termios stored_settings;
void echo_off(void)
{
    struct termios new_settings;
    tcgetattr(0, &stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ECHO);
    new_settings.c_lflag &= (~ICANON);
    tcsetattr(0,TCSANOW, &new_settings);

    return ;
}

void echo_on(void)
{
    tcsetattr(0, TCSANOW, &stored_settings);
    return ;
}

void get_pass(char *pass)
{
    char buf;
    int i=0;

    printf("Passwd : ");
    echo_off();
    while ((buf=getc(stdin)) != '\n')
    {
        pass[i] = buf;
        printf("%s", "*");
        i ++;
    }
    echo_on();
}

int main()
{
    char pass[16];
    memset(pass, 0x00, 16);
    get_pass(pass);
    printf("\nYour input : %s\n", pass);
    return 1;
}
