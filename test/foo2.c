/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:00:51 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/13 20:09:26 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <term.h>
#include <stdio.h>

# define Unix

char *tgetstr ();

char *cl_string, *cm_string;
int height;
int width;
int auto_wrap;

char PC;   /* For tputs.  */
char *BC;  /* For tgoto.  */
char *UP;

int	main(void)
{
#ifdef Unix
  /* Here we assume that an explicit term_buffer
     was provided to tgetent.  */
  char *buffer
    = (char *) malloc (2048);
  printf("UNIX\n");
#define BUFFADDR &buffer
#else
  printf("GNU\n");
#define BUFFADDR 0
#endif

  char *temp;

  /* Extract information we will use.  */
  cl_string = tgetstr ("cl", BUFFADDR);
  cm_string = tgetstr ("cm", BUFFADDR);
  auto_wrap = tgetflag ("am");
  height = tgetnum ("li");
  width = tgetnum ("co");

  /* Extract information that termcap functions use.  */
  temp = tgetstr ("pc", BUFFADDR);
  PC = temp ? *temp : 0;
  BC = tgetstr ("le", BUFFADDR);
  UP = tgetstr ("up", BUFFADDR);

  return (0);
}
