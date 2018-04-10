/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:38:36 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/04 19:38:40 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atod_p3(char c, int *space_check_signe_point,
	double *ret, double *fact)
{
	if (c == '.' && space_check_signe_point[3] == 0)
	{
		space_check_signe_point[3] = 1;
		return (0);
	}
	if (c < '0' || '9' < c)
		return (1);
	if (space_check_signe_point[3] == 0)
		*ret = *ret * 10 + (int)(c - '0');
	else
	{
		*ret += ((int)(c - '0') * *fact);
		*fact *= 0.1;
	}
	return (0);
}

static int	ft_atod_p2(char c, int *space_check_signe_point,
	double *ret, double *fact)
{
	if (space_check_signe_point[1] == 0)
	{
		if (c == '-')
		{
			space_check_signe_point[1] = 1;
			space_check_signe_point[2] = -1;
			return (0);
		}
		if (c < '0' || '9' < c)
			return (1);
		space_check_signe_point[2] = 1;
		space_check_signe_point[1] = 1;
	}
	return (ft_atod_p3(c, space_check_signe_point, ret, fact));
}

double		ft_atod(char *str)
{
	double	ret;
	size_t	iter;
	double	fact;
	int		space_check_signe_point[4];

	ret = 0;
	iter = 0;
	fact = 0.1;
	space_check_signe_point[0] = 0;
	space_check_signe_point[1] = 0;
	space_check_signe_point[2] = 0;
	space_check_signe_point[3] = 0;
	while (str[iter])
	{
		if (!ft_iswhitespace(str[iter]))
			space_check_signe_point[0] = 1;
		if (space_check_signe_point[0] == 1)
			if (ft_atod_p2(str[iter],
				space_check_signe_point, &ret, &fact) == 1)
				break ;
		iter++;
	}
	return (ret * space_check_signe_point[1]);
}
