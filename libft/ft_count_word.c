/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:10:31 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/08 17:10:34 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(const char *str, char c)
{
	int	nb_words;

	nb_words = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			nb_words++;
		while (*str != c && *str)
			str++;
	}
	return (nb_words);
}
