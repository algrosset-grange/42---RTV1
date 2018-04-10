/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:25:14 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:25:22 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_free_material(t_scene *scene)
{
	t_material *current;
	t_material *next;

	current = scene->mmaterials;
	while (current != NULL)
	{
		next = current->next;
		ft_memdel((void **)&current);
		current = next;
	}
}

static void	ft_free_light(t_scene *scene)
{
	t_light *current;
	t_light *next;

	current = scene->mlights;
	while (current != NULL)
	{
		next = current->next;
		ft_memdel((void **)&current);
		current = next;
	}
}

void		ft_free_scene_p3(t_scene *scene)
{
	ft_free_material(scene);
	ft_free_light(scene);
}
