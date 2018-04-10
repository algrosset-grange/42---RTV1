/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:36:32 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/08 20:38:21 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim_f_b(const char *s)
{
	size_t	beg;

	beg = 0;
	while (s[beg] && (s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t'))
		beg++;
	return (beg);
}

static size_t	ft_strtrim_f_e(const char *s, size_t len)
{
	size_t	beg;

	beg = 0;
	while ((s[len - 1 - beg] == ' ' ||
			s[len - 1 - beg] == '\n' || s[len - 1 - beg] == '\t'))
		beg++;
	return (beg);
}

char			*ft_strtrim(const char *s)
{
	char	*str;
	size_t	str_len;
	size_t	ove_beg;
	size_t	ove_end;
	size_t	new_le;

	if (!s)
		return (NULL);
	str_len = (size_t)ft_strlen(s);
	if (str_len == 0 || str_len == ft_strtrim_f_b(s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	ove_beg = ft_strtrim_f_b(s);
	ove_end = ft_strtrim_f_e(s, str_len);
	new_le = str_len - ove_beg - ove_end;
	str = (char *)malloc(sizeof(char) * new_le + 1);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, s + ove_beg, new_le);
	str[new_le] = '\0';
	return (str);
}
