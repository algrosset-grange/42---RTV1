/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_str_occurence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:20:51 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 12:20:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_str_occurence(const char *str, char *to_find)
{
	size_t	iter;
	size_t	iter2;
	int		count;

	iter = 0;
	iter2 = 0;
	count = 0;
	while (str[iter])
	{
		if (str[iter] == to_find[iter2])
			iter2++;
		else
			iter2 = 0;
		if (iter2 == 0 && str[iter] == to_find[iter2])
			iter2++;
		if (!to_find[iter2])
		{
			count++;
			iter2 = 0;
		}
		iter++;
	}
	return (count);
}
