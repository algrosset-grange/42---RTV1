/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:45:09 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 10:45:13 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	ite[2];

	ite[0] = 0;
	ite[1] = 0;
	while (ite[0] < n)
	{
		dest[ite[0]] = src[ite[1]];
		if (src[ite[1]])
			ite[1]++;
		ite[0]++;
	}
	return (dest);
}
