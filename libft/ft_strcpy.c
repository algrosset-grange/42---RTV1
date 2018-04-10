/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:11:07 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/04 19:11:11 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	ite;

	ite = 0;
	while (src[ite])
	{
		dest[ite] = src[ite];
		ite++;
	}
	dest[ite] = src[ite];
	return (dest);
}
