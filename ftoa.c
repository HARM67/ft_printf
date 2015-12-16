/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_base_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:43:32 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/16 10:43:03 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*r_ftoae(double nb, char *tmp, int precision)
{
	char	*rt;

	if (nb < 0.0)
	{
		*tmp = '-';
		r_ftoae(-nb, tmp + 1, precision);
		return (tmp);
	}
	else if (nb > 9.0)
	{
		rt = r_ftoae(nb / 10, tmp, precision);
		*rt = (int)nb % 10 + '0';
		return (rt + 1);
	}
	else if ((int)nb > 0)
		*tmp = nb + '0';
	return (tmp + 1);
}

//static char *r_ftoae

//static void	arrondit(char **f, int precision);

char		*ftoa(double n, int precision)
{
	char tmp[21];
	char *rt;

	if (n == 0)
		return (ft_strdup("0.0"));
	ft_bzero(tmp, 21);
	r_ftoae(n, tmp, precision + 1);
	rt = ft_strdup(tmp);
	return (rt);
}
