/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 11:55:24 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/26 11:55:51 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccat(char *dst, const char *src, int c)
{
	size_t	ite1;
	size_t	ite2;

	ite1 = 0;
	ite2 = 0;
	if (ft_strlen(src) == 0)
		return (dst);
	while (dst[ite1])
		ite1++;
	while (src[ite2])
	{
		dst[ite1 + ite2] = src[ite2];
		if (src[ite2] == c)
		{
			dst[ite1 + ite2] = '\0';
			return ((char *)dst + ite1 + ite2 + 1);
		}
		ite2++;
	}
	dst[ite1 + ite2] = src[ite2];
	return (dst);
}
