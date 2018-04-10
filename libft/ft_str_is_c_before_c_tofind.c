/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_c_before_c_tofind.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:03:53 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 12:10:27 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_c_before_c_tofind(char *str, char to_find)
{
	int	iter;

	iter = 0;
	while (ft_iswhitespace(str[iter]))
		iter++;
	if (str[iter] == to_find)
		return (0);
	return (1);
}
