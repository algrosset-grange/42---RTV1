/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:20:15 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/06 10:20:17 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*dest;
	char	*sorc;
	size_t	i;

	dest = (char *)dst;
	sorc = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sorc[i];
		if (sorc[i] == c)
			return ((void *)dst + i + 1);
		i++;
	}
	return (NULL);
}
