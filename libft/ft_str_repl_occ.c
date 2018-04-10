/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_repl_occ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:09:27 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/06 16:09:29 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_repl_occ(char **str, char occ, char rep)
{
	int i;

	i = 0;
	if (*str != NULL)
		while (str[0][i])
		{
			if (str[0][i] == occ)
				str[0][i] = rep;
			i++;
		}
}
