/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:55:40 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/13 18:55:42 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*bye;
	t_list	*temp;

	if (!alst || !del)
		return ;
	bye = *alst;
	while (bye)
	{
		temp = bye->next;
		del(bye->content, bye->content_size);
		free(bye);
		bye = temp;
	}
	*alst = NULL;
}
