/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:20:39 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/10 16:56:41 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*sorc;
	char	*temp;
	size_t	i;

	dest = (char *)dst;
	sorc = (char *)src;
	if (!(temp = (char *)malloc(sizeof(char) * n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		temp[i] = sorc[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest[i] = temp[i];
		i++;
	}
	ft_strdel(&temp);
	return (dst);
}
