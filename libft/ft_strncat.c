/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:30:33 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 15:30:35 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t	ite1;
	size_t	ite2;

	if (len == 0)
		return (dst);
	ite1 = 0;
	while (dst[ite1])
		ite1++;
	ite2 = 0;
	while (src[ite2] && ite2 < len)
	{
		dst[ite1 + ite2] = src[ite2];
		ite2++;
	}
	dst[ite1 + ite2] = '\0';
	return (dst);
}
