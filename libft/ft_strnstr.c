/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:45:10 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 11:45:14 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	iter;
	size_t	begin;
	size_t	lenght_to_find;

	lenght_to_find = 0;
	while (to_find[lenght_to_find])
		lenght_to_find++;
	if (lenght_to_find == '\0')
		return ((char *)str);
	iter = 0;
	begin = 0;
	while (str[iter] && iter < len)
	{
		while (to_find[begin] == str[iter + begin] && (iter + begin) < len)
		{
			if (begin == lenght_to_find - 1)
				return ((char *)str + iter);
			begin++;
		}
		begin = 0;
		iter++;
	}
	return (0);
}
