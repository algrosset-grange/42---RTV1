/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:56:16 by agrosset          #+#    #+#             */
/*   Updated: 2016/11/13 18:56:19 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*n_temp;
	t_list	*new_lst;

	if (!lst || !f)
		return (NULL);
	new_lst = f(lst);
	temp = lst->next;
	n_temp = new_lst;
	while (temp && n_temp)
	{
		n_temp->next = f(temp);
		n_temp = n_temp->next;
		temp = temp->next;
	}
	return (new_lst);
}
