/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:56:13 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/07 09:56:17 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strsplit_count_s_w(const char *str, int *size_word, char c)
{
	int		one_word_size;
	int		nu_word;

	nu_word = 0;
	one_word_size = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			nu_word++;
			size_word[nu_word - 1] = 0;
		}
		while (*str != c && *str)
		{
			size_word[nu_word - 1] = size_word[nu_word - 1] + 1;
			str++;
		}
		size_word[nu_word - 1] = size_word[nu_word - 1] + 1;
	}
}

static int	ft_strsplit_malloc(int nb_words, char **resul, int *size_words)
{
	size_t	iter;

	iter = 0;
	while (iter < (size_t)nb_words)
	{
		resul[iter] = malloc(sizeof(char) * size_words[iter]);
		if (resul[iter] == NULL)
			return (0);
		iter++;
	}
	return (1);
}

static void	ft_strsplit_compl_w(int nb_w, const char *str, char **res, char c)
{
	int		nu_word;
	int		posi_word;

	nu_word = 0;
	while (*str && nu_word < nb_w)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			posi_word = 0;
			nu_word++;
		}
		while (*str != c && *str)
		{
			res[nu_word - 1][posi_word] = *str;
			posi_word++;
			str++;
		}
		res[nu_word - 1][posi_word] = '\0';
	}
}

char		**ft_strsplit(const char *s, char c)
{
	char	**resul;
	int		*size_words;
	int		nb_words;

	if (!s)
		return (NULL);
	nb_words = ft_count_word(s, c);
	resul = malloc(sizeof(char*) * (nb_words + 1));
	if (resul == 0)
		return (0);
	size_words = malloc(sizeof(int) * nb_words);
	if (size_words == NULL)
		return (NULL);
	ft_strsplit_count_s_w(s, size_words, c);
	if (ft_strsplit_malloc(nb_words, resul, size_words) == 0)
		return (NULL);
	resul[nb_words] = malloc(sizeof(char) * 1);
	resul[nb_words] = 0;
	if (nb_words > 0)
		ft_strsplit_compl_w(nb_words, s, resul, c);
	return (resul);
}
