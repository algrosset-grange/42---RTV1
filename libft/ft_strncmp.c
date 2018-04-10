/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:53:46 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/04 19:53:48 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ite;
	int		resul;

	if (n == 0)
		return (0);
	ite = 0;
	while (ite < n - 1 && s1[ite] == s2[ite] && s1[ite])
		ite++;
	resul = (unsigned char)s1[ite] - (unsigned char)s2[ite];
	return (resul);
}
