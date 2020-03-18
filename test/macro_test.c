/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 02:41:31 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/18 03:00:18 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

# define ENV (getenv("TERM") ? 0 : 1)
#if ENV
	exit(0);
#endif

int main(void)
{
	printf("HI\n");
//	printf("%s\n", ENV);

	return (0);
}
