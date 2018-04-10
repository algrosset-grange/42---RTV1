/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:45:37 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 13:45:39 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_take_int_until_p2(char c, int *check_signe_space, long *ret)
{
	if (check_signe_space[0] == NOT_DONE)
	{
		if (c == '-')
		{
			check_signe_space[0] = DONE;
			check_signe_space[1] = -1;
			return (NO_ERROR);
		}
		if (ft_iswhitespace(c))
			return (NO_ERROR);
		if (c < '0' || '9' < c)
			return (ERROR);
		check_signe_space[1] = 1;
		check_signe_space[0] = DONE;
	}
	if (ft_iswhitespace(c))
	{
		check_signe_space[2] = DONE;
		return (NO_ERROR);
	}
	if (check_signe_space[2] == DONE || c < '0' || '9' < c)
		return (ERROR);
	*ret = *ret * 10 + (int)(c - '0');
	return (NO_ERROR);
}

static int	ft_take_int_until(char *str, int *nb, char c)
{
	long	ret;
	size_t	iter;
	int		check_signe_space[3];

	ret = 0;
	iter = 0;
	check_signe_space[0] = NOT_DONE;
	check_signe_space[1] = 0;
	while (str[iter] && str[iter] != c)
	{
		if (ft_take_int_until_p2(str[iter], check_signe_space, &ret) == ERROR)
			return (ERROR);
		iter++;
	}
	if ((ret > MAX_INT && check_signe_space[1] == 1) ||
		(ret > MIN_INT && check_signe_space[1] == -1))
		return (ERROR);
	*nb = ret * check_signe_space[1];
	return (NO_ERROR);
}

static int	ft_take_uns_int_until(t_checkjson *check, char *str,
	int *nb, char c)
{
	int	ret;

	if (ft_take_int_until(str, &ret, c) == ERROR)
		return (ft_check_error(check, ERROR_NOT_INT));
	if (ret < 0)
		return (ft_check_error(check, ERROR_NOT_UNS_INT));
	*nb = ret;
	return (NO_ERROR);
}

int			ft_check_int(t_checkjson *check, char *str, int *var)
{
	char	*verif_val;
	int		nb;

	if (ft_find_number(check, str, &verif_val) == ERROR)
		return (ERROR);
	if (ft_take_int_until(verif_val, &nb, check->c_to_find) == ERROR)
		return (ERROR);
	*var = nb;
	return (NO_ERROR);
}

int			ft_check_uns_int(t_checkjson *check, char *str, int *var)
{
	char	*verif_val;
	int		nb;

	if (ft_find_number(check, str, &verif_val) == ERROR)
		return (ERROR);
	if (ft_take_uns_int_until(check, verif_val, &nb, check->c_to_find) == ERROR)
		return (ERROR);
	*var = nb;
	return (NO_ERROR);
}
