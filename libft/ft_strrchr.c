/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:20:51 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 12:20:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	size_t	iter;

	iter = 0;
	while (str[iter])
		iter++;
	if (str[iter] == to_find)
		return ((char *)str + iter);
	while (iter > 0)
	{
		if (str[iter] == to_find)
			return ((char *)str + iter);
		iter--;
	}
	if (str[0] == to_find)
		return ((char *)str);
	return (0);
}
