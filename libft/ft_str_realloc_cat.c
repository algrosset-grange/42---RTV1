/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc_cat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:16:46 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/25 13:16:51 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_realloc_cat(char **dst, const char *src)
{
	ft_str_realloc(dst, ft_strlen(src));
	ft_strcat(*dst, src);
	return ;
}
