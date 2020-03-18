/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csize.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 23:23:31 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/13 23:23:53 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <termios.h>

struct termios old_settings;
int main()
{
    struct termios new_settings;
    int size;

    tcgetattr(0, &new_settings);
    size = new_settings.c_cflag&CSIZE ;

    if (size == CS7) printf("7bits/byte\n");
    else if (size == CS8) printf("8bits/byte\n");
}
