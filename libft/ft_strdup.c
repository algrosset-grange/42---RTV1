/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:11:14 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 12:48:04 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dup;

	len = ft_strlen(src);
	if (len == -1)
		return (NULL);
	dup = malloc(sizeof(*src) * len + 1);
	if (dup == NULL)
		return (NULL);
	return (ft_strcpy(dup, src));
}
