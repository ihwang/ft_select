/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:41:36 by ihwang            #+#    #+#             */
/*   Updated: 2020/02/28 00:56:25 by tango            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_bzero(void *s, size_t n)
{
	char	*pt;

	pt = s;
	while (n-- > 0)
		*(pt++) = '\0';
}
