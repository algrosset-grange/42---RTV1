/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cmp_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:20:51 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 12:20:54 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_cmp_ext(const char *str, const char *extension)
{
	int	iter;

	iter = ft_strlen(str);
	while (iter - 1 >= 0)
	{
		if (str[iter] == '.')
			if (!ft_strcmp((str + iter + 1), extension))
				return (1);
	}
	return (0);
}
