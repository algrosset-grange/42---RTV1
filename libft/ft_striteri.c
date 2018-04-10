/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:34:08 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/09 12:34:10 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	len;
	size_t	ite;

	if (!(s) || !(f))
		return ;
	len = ft_strlen(s);
	ite = 0;
	while (ite < len)
	{
		f((unsigned int)ite, (char *)(s + ite));
		ite++;
	}
}
