/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:51:26 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 14:51:29 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
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
		ite2++;
	}
	dst[ite1 + ite2] = src[ite2];
	return (dst);
}
