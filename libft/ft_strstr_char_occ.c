/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_char_occ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:59:13 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 11:59:17 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr_char_occ(char *str, int c, int occ)
{
	size_t	iter;
	int		c_occ;

	iter = 0;
	c_occ = 0;
	while (str[iter])
	{
		if (str[iter] == c)
			c_occ++;
		if (c_occ == occ)
			return (str + iter);
		iter++;
	}
	return (str);
}
