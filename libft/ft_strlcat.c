/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:06:57 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 17:06:59 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	init;

	if (ft_strlen(dst) >= size)
		return (ft_strlen(src) + size);
	init = ft_strlen(dst) + ft_strlen(src);
	ft_strncat(dst, src, (size - ft_strlen(dst) - 1));
	return (init);
}
