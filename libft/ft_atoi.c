/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:38:36 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/04 19:38:40 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif_atoi(int ascii)
{
	if (ascii >= 48 && ascii <= 57)
		return (1);
	return (0);
}

static int	ft_atoi_next(const char *str, int iterator)
{
	int		veri_c_ascii;
	int		answer;

	answer = 0;
	while (str[iterator] != '\0')
	{
		veri_c_ascii = str[iterator];
		if (verif_atoi(veri_c_ascii))
		{
			veri_c_ascii = veri_c_ascii - 48;
			answer = answer * 10 + veri_c_ascii;
			iterator++;
		}
		else
		{
			break ;
		}
	}
	return (answer);
}

static int	verif_nega(int b)
{
	if ((b >= 48 && b <= 57))
		return (1);
	if (b == 45)
		return (2);
	if (b == 43)
		return (3);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		answer;
	int		iterator;
	int		nega;

	iterator = 0;
	while (ft_iswhitespace(str[iterator]))
		iterator++;
	nega = verif_nega((int)str[iterator]);
	if (!nega)
		return (0);
	if (nega == 2 || nega == 3)
		iterator++;
	answer = ft_atoi_next(str, iterator);
	if (nega == 2 && answer > 0)
		answer = -answer;
	return (answer);
}
