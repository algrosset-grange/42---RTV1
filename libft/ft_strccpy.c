/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:20:15 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/06 10:20:17 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(char *dst, const char *src, int c)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		if (src[i] == c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (dst);
}
