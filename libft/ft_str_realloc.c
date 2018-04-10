/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:32:35 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/25 12:32:38 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_realloc(char **str, size_t add_size)
{
	char	*new_str;
	size_t	str_l;

	str_l = 0;
	if (*str != NULL)
		str_l = ft_strlen(*str);
	new_str = ft_strnew(str_l + add_size);
	if (*str != NULL)
	{
		if (*str != NULL)
			ft_strcpy(new_str, *str);
		ft_strdel(str);
	}
	*str = new_str;
	return ;
}
