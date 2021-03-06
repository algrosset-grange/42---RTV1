/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:33:06 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/09 13:33:09 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isascii(char *str)
{
	while (*str)
	{
		if (!ft_isascii((int)*str))
			return (0);
		str++;
	}
	return (1);
}
