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

static void	ft_free_sphere(t_scene *scene)
{
	t_sphere *current;
	t_sphere *next;

	current = scene->mspheres;
	while (current != NULL)
	{
		next = current->next;
		ft_memdel((void **)&current);
		current = next;
	}
}

static void	ft_free_plane(t_scene *scene)
{
	t_plane *current;
	t_plane *next;

	current = scene->mplanes;
	while (current != NULL)
	{
		next = current->next;
		ft_memdel((void **)&current);
		current = next;
	}
}

static void	ft_free_cylinder(t_scene *scene)
{
	t_cylinder *current;
	t_cylinder *next;

	current = scene->mcylinders;
	while (current != NULL)
	{
		next = current->next;
		ft_memdel((void **)&current);
		current = next;
	}
}

static void	ft_free_cone(t_scene *scene)
{
	t_cone *current;
	t_cone *next;

	current = scene->mcones;
	while (current != NULL)
	{
		next = current->next;
		ft_memdel((void **)&current);
		current = next;
	}
}

void		ft_free_scene_p2(t_scene *scene)
{
	ft_free_sphere(scene);
	ft_free_plane(scene);
	ft_free_cylinder(scene);
	ft_free_cone(scene);
}
