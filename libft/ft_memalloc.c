/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:46:19 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/08 20:46:20 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*p;
	char	*str;

	p = (void *)malloc(sizeof(void) * size);
	if (p == NULL)
		return (NULL);
	str = (char *)p;
	while (size > 0)
	{
		str[size - 1] = '\0';
		size--;
	}
	return (p);
}
