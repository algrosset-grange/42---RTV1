/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:20:29 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 12:20:30 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	size_t	iter;

	iter = 0;
	while (str[iter])
	{
		if (str[iter] == (char)to_find)
			return ((char *)str + iter);
		iter++;
	}
	if (str[iter] == (char)to_find)
		return ((char *)str + iter);
	return (NULL);
}
