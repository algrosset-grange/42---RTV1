/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:33:16 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 13:33:17 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_take_double_until_p3(char c, int *check_signe_space_point,
	double *ret, double *fact)
{
	if (ft_iswhitespace(c))
	{
		check_signe_space_point[2] = DONE;
		return (0);
	}
	if (c == '.' && check_signe_space_point[2] == NOT_DONE)
	{
		check_signe_space_point[3] = DONE;
		if (check_signe_space_point[2] == DONE)
			return (ERROR);
		return (NO_ERROR);
	}
	if (check_signe_space_point[2] == DONE || c < '0' || '9' < c)
		return (ERROR);
	if (check_signe_space_point[3] == NOT_DONE)
		*ret = *ret * 10 + (int)(c - '0');
	else
	{
		*ret += ((int)(c - '0') * *fact);
		*fact *= 0.1;
	}
	return (NO_ERROR);
}

static int	ft_take_double_until_p2(char c, int *check_signe_space_point,
	double *ret, double *fact)
{
	if (check_signe_space_point[0] == NOT_DONE)
	{
		if (c == '-')
		{
			check_signe_space_point[0] = DONE;
			check_signe_space_point[1] = -1;
			return (NO_ERROR);
		}
		if (ft_iswhitespace(c))
			return (NO_ERROR);
		if (c < '0' || '9' < c)
			return (ERROR);
		check_signe_space_point[1] = 1;
		check_signe_space_point[0] = DONE;
	}
	return (ft_take_double_until_p3(c, check_signe_space_point, ret, fact));
}

int			ft_take_double_until(char *str, double *nb, char c)
{
	double	ret;
	size_t	iter;
	double	fact;
	int		check_signe_space_point[4];

	ret = 0;
	iter = 0;
	fact = 0.1;
	check_signe_space_point[0] = NOT_DONE;
	check_signe_space_point[1] = 0;
	check_signe_space_point[2] = NOT_DONE;
	check_signe_space_point[3] = NOT_DONE;
	while (str[iter] && str[iter] != c)
	{
		if (ft_take_double_until_p2(str[iter],
			check_signe_space_point, &ret, &fact) == ERROR)
			return (ERROR);
		iter++;
	}
	*nb = ret * check_signe_space_point[1];
	return (NO_ERROR);
}

int			ft_take_uns_double_until(char *str, double *nb, char c)
{
	double	ret;

	if (ft_take_double_until(str, &ret, c) == ERROR)
		return (ERROR);
	if (ret < 0)
		return (ERROR);
	*nb = ret;
	return (NO_ERROR);
}
