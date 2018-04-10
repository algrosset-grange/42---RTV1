/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_occ_exc_wp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:16:56 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 12:16:57 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_char_occ_exc_wp(char *str, char c_occ, int occ, char to_find)
{
	int	iter;
	int	nb_occ;

	iter = 0;
	nb_occ = 0;
	while (str[iter] && nb_occ < occ)
	{
		if (str[iter] == c_occ)
			nb_occ++;
		iter++;
	}
	if (!str[iter] || ft_str_is_c_before_c_tofind(&(str[iter]), to_find))
		return (1);
	return (0);
}
