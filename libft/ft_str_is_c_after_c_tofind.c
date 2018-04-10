/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_c_after_c_tofind.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:12:29 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 12:12:30 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_c_after_c_tofind(char *str, char to_find)
{
	int	iter;

	iter = 0;
	while (str[iter])
		iter++;
	iter--;
	while (ft_iswhitespace(str[iter]))
		iter--;
	if (str[iter] == to_find)
		return (0);
	return (1);
}
