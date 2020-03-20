/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:48:37 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/19 17:15:03 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#include "../libft/includes/libft.h"
#include <term.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>

# define COL (tgetnum("co"))
# define ROW (tgetnum("li"))

# define CL (tgetstr("cl", NULL))
# define CM (tgetstr("cm", NULL))
# define US (tgetstr("us", NULL))
# define UE (tgetstr("ue", NULL))
# define VE (tgetstr("ve", NULL))
# define VI (tgetstr("vi", NULL))
# define SO (tgetstr("so", NULL))
# define SE (tgetstr("se", NULL))
# define ME (tgetstr("me", NULL))

# define ISSP(b) (b[0] == ' ' && b[1] == '\0')
# define ISUP(b) (b[0] == 27 && b[1] == 91 && b[2] == 'A')
# define ISDW(b) (b[0] == 27 && b[1] == 91 && b[2] == 'B')
# define ISLE(b) (b[0] == 27 && b[1] == 91 && b[2] == 'D')
# define ISRT(b) (b[0] == 27 && b[1] == 91 && b[2] == 'C')
# define ISESC(b) (b[0] == 27 && b[1] == '\0')
# define ISBS(b) (b[0] == 127 && b[1] == '\0')
# define ISDE(b) (b[0] == 27 && b[1] == 91 && b[2] == '3' && b[3] == '~') 
# define ISEN(b) (b[0] == '\n' && b[1] == '\0')

# define NEXT 1
# define STAY 0

typedef struct termios	t_term;

typedef struct	s_t
{
	t_term		o_set;
	int			ac;
	int			curr;
	int			*sel;
//	int			col;
//	int			maxcol;
	char		**av;
	char		input[8];
}				t_t;

t_t				g_t;

void			print_args(int x, int y);
void			parse_key(void);
void			bs_del_key(void);
void			enter_key(void);
void			space_key(int opt);
void			esc_key(int opt);

#endif
