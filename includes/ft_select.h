/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:48:37 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/18 02:41:13 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#if !(getenv("TERM"))
	

# define COL (tgetent("co"))
# define ROW (tgetent("li"))

# define VI (tgetstr("vi", NULL))
# define CL (tgetstr("cl", NULL))
# define CM (tgetstr("cm", NULL))
# define US (tgetstr("us", NULL))
# define UE (tgetstr("ue", NULL))
# define VE (tgetstr("ve", NULL))
# define ME (tgetstr("me", NULL))

# define ISSP(b) (b[0] == ' ' && b[1] == '\0')
# define ISUP(b) (b[0] == 27 && b[1] == 91 && b[2] == 'A')
# define ISDW(b) (b[0] == 27 && b[1] == 91 && b[2] == 'B')
# define ISLE(b) (b[0] == 27 && b[1] == 91 && b[2] == 'D')
# define ISRT(b) (b[0] == 27 && b[1] == 91 && b[2] == 'C')
# define ISESC(b) (b[0] == 27 && b[1] == '\0')
# define ISBS(b) (b[0] == 127 && b[1] == '\0')
# define ISDE(b) (b[0] == 27 && b[1] == 91 && b[2] == '3' && b[3] == '~') 

#include "../libft/includes/libft.h"
#include <term.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>


typedef struct termios	t_term;

typedef struct	s_t
{
	t_term		o_set;
	int			ac;
	int			curr;
	int			sel;
	int			col;
	int			maxcol;
	char		**av;
	char		input[8];
}				t_t;


#endif
