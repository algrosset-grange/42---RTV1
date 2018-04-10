/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_iswhitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:01:52 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 12:01:55 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_iswhitespace(char *str)
{
	size_t	iter;

	iter = 0;
	while (str[iter])
	{
		if (!ft_iswhitespace(str[iter]))
			return (0);
		iter++;
	}
	return (1);
}
