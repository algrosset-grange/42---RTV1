/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:41:44 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 10:42:04 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	iter;
	size_t	begin;
	size_t	lenght_to_find;

	lenght_to_find = ft_strlen(to_find);
	if (lenght_to_find == '\0')
		return ((char *)str);
	iter = 0;
	begin = 0;
	while (str[iter])
	{
		while (to_find[begin] == str[iter + begin])
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
