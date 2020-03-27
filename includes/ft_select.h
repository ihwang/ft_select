/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 16:48:37 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/27 16:34:44 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libft.h"
# include <term.h>
# include <termios.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <sys/ioctl.h>
# include <sys/stat.h>

# define STAY 0
# define NEXT 1
# define NORM 0
# define NOARG -1
# define NOENV -2
# define INIT "\033[0m"
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREN "\033[32m"
# define YELW "\033[33m"
# define BLUE "\033[34m"
# define MGTA "\033[35m"
# define CYAN "\033[36m"

typedef struct termios	t_term;
typedef struct stat		t_stat;

typedef struct			s_t
{
	t_term				o_set;
	int					ac;
	int					curr;
	int					*sel;
	char				**av;
	char				input[8];
}						t_t;

t_t						g_t;

void					print_args(int x, int y);
void					parse_key(void);
void					down_key(void);
void					bs_del_key(void);
void					enter_key(void);
void					space_key(int opt);
void					esc_key(int opt);
int						is_selected(int i);
void					sig_set(void);

#endif
