/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:07:03 by ihwang            #+#    #+#             */
/*   Updated: 2020/03/09 18:08:17 by ihwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_addchar(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i])
		NULL;
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}
