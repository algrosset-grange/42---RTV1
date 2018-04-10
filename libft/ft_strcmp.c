/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:47:43 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/04 16:47:55 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		resul;
	size_t	ite;

	ite = 0;
	while (s1[ite] && (unsigned char)s1[ite] == (unsigned char)s2[ite])
		ite++;
	resul = (unsigned char)s1[ite] - (unsigned char)s2[ite];
	return (resul);
}
