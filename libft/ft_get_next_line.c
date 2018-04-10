/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:05:49 by agrosset          #+#    #+#             */
/*   Updated: 2016/12/10 20:22:15 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void		ft_free_plist(t_plist *file, t_plist **first)
{
	if (file->befo != NULL && file->next == NULL)
		file->befo->next = NULL;
	if (file->befo == NULL && file->next != NULL)
		file->next->befo = NULL;
	if (file->befo != NULL && file->next != NULL)
	{
		file->next->befo = file->befo;
		file->befo->next = file->next;
	}
	if ((*first)->fd == file->fd)
		*first = file->next;
	file->next = NULL;
	file->befo = NULL;
	ft_strdel(&(file->tab));
	ft_strdel(&(file->ret_line));
	free(file);
}

static t_plist	*ft_file_actu(int fd_n, t_plist **first)
{
	t_plist	*temp;

	temp = *first;
	if (temp != NULL)
		while (temp != NULL)
		{
			if (temp->fd == fd_n)
				return (temp);
			else
				temp = temp->next;
		}
	if ((temp = ft_memalloc(sizeof(t_plist))) == NULL ||
		(temp->tab = ft_strnew(BUFF_SIZE)) == NULL)
		return (NULL);
	temp->read = BUFF_SIZE;
	temp->fd = fd_n;
	temp->resid = NULL;
	temp->ret_line = NULL;
	temp->next = *first;
	temp->befo = NULL;
	if (*first != NULL)
		(*first)->befo = temp;
	*first = temp;
	return (temp);
}

static void		ft_complet_line(t_plist *file)
{
	size_t		i;
	char		*next_str;

	if (file->resid[0] == '\n')
		ft_strcpy(file->resid, &(file->resid[1]));
	ft_str_realloc(&(file->ret_line), BUFF_SIZE);
	i = 0;
	ft_strccat(file->ret_line, file->resid, '\n');
	while (file->resid[i] && file->resid[i] != '\n')
		i++;
	next_str = &(file->resid[i]);
	file->resid = ft_strdup_salloc(&next_str);
	if (!ft_strlen(file->resid))
		ft_strdel(&(file->resid));
}

static void		ft_complet_resid(t_plist *file)
{
	size_t		i;
	char		*next_str;

	ft_str_realloc(&(file->ret_line), BUFF_SIZE);
	i = 0;
	ft_strccat(file->ret_line, file->tab, '\n');
	while (file->tab[i] && file->tab[i] != '\n')
		i++;
	next_str = &(file->tab[i]);
	file->resid = ft_strdup_salloc(&next_str);
	if (!ft_strlen(file->resid))
		ft_strdel(&(file->resid));
	ft_strclr(file->tab);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_plist	*list = NULL;
	t_plist			*file;

	if (fd < 0 || (file = ft_file_actu(fd, &list)) == NULL)
		return (-1);
	file->a_lu = 0;
	if (file->resid != NULL)
		ft_complet_line(file);
	while (file->read == BUFF_SIZE && file->resid == NULL)
	{
		if ((file->read = read(fd, file->tab, BUFF_SIZE)) == -1)
			return (-1);
		if (file->read != 0)
			file->a_lu = 1;
		if (file->read != 0)
			ft_complet_resid(file);
	}
	*line = ft_strdup_salloc(&(file->ret_line));
	if (file->read != BUFF_SIZE && file->resid == NULL && !file->a_lu)
	{
		ft_free_plist(file, &list);
		return (0);
	}
	ft_strdel(&(file->ret_line));
	return (1);
}
