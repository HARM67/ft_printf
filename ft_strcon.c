/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:13:16 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/14 07:01:05 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strncon(char **s1, const char *s2, size_t l_s1, size_t l_s2)
{
	char	*rt;
	int i;

	i = 0;
//	if (*s1 == 0)
//	{
//		*s1 = ft_strdup(s2);
//		return (1);
//	}
	rt = ft_memalloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (rt == 0)
		return (-1);
	while (i < l_s1)
	{
		rt[i] = *s1[i];
		i++;
	}
	i = 0;
	while (i < l_s2)
	{
		rt[l_s1 + i] = s2[i];
		i++;
	}
	rt[l_s1 + l_s2] = 0;
	//free(*s1);
	*s1 = rt;
	return (1);
}
