/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_salloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:38:15 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/05 12:48:27 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_salloc(char **str)
{
	size_t	cp;

	cp = 0;
	if (*str == NULL)
		*str = ft_strnew(0);
	while (str[0][cp])
		cp++;
	return (cp);
}
