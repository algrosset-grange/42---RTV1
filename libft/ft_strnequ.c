/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:44:05 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/08 20:44:07 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	ite;

	if (!s1 || !s2)
		return (0);
	ite = 0;
	while (s1[ite] && ite < n)
	{
		if (s1[ite] != s2[ite])
			return (0);
		ite++;
	}
	if (s1[ite] != s2[ite] && n < ite)
		return (0);
	return (1);
}
