/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:13:16 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/16 17:28:02 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncon(char **s1, char **s2, size_t l_s1, size_t l_s2, int flag)
{
	char	*rt;
	int i;

	i = 0;
	if (l_s1 == -1)
		l_s1 = ft_strlen(*s1);
	if (l_s2 == -1)
		l_s2 = ft_strlen(*s2);
	rt = ft_memalloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (rt == 0)
		return (0);
	while (i < l_s1)
	{
		rt[i] = (*s1)[i];
		i++;
	}
	i = 0;
	while (i < l_s2)
	{
		rt[l_s1 + i] = (*s2)[i];
		i++;
	}
	rt[l_s1 + l_s2] = 0;
	(flag & 0x4  && *s1) ? ft_bzero(*s1, l_s1) : 0;
	(flag & 0x8  && *s2) ? ft_bzero(*s2, l_s2) : 0;
	(flag & 0x1  && *s1) ? free(*s1) : 0;
	(flag & 0x2  && *s2) ? free(*s2) : 0;
	return (rt);
}
