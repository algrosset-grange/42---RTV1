/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_occurence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:20:51 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 12:20:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_occurence(const char *str, int to_find)
{
	size_t	iter;
	int		count;

	iter = 0;
	count = 0;
	while (str[iter])
	{
		if (str[iter] == to_find)
			count++;
		iter++;
	}
	return (count);
}
