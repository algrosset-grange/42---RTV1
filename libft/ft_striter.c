/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:45:30 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/08 20:45:33 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	len;
	size_t	ite;

	if (!(s) || !(f))
		return ;
	len = ft_strlen(s);
	ite = 0;
	while (ite < len)
	{
		f((char *)(s + ite));
		ite++;
	}
}
