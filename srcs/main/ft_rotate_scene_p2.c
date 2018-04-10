/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_scene_p2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:29:13 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:29:14 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_rotate_plane(t_plane *current, t_vector *rotate)
{
	while (current != NULL)
	{
		ft_rotate(&current->origin, rotate);
		ft_rotate(&current->direction, rotate);
		current = current->next;
	}
}

static void	ft_rotate_cylinder(t_cylinder *current, t_vector *rotate)
{
	while (current != NULL)
	{
		ft_rotate(&current->origin, rotate);
		ft_rotate(&current->direction, rotate);
		current = current->next;
	}
}

static void	ft_rotate_cone(t_cone *current, t_vector *rotate)
{
	while (current != NULL)
	{
		ft_rotate(&current->origin, rotate);
		ft_rotate(&current->direction, rotate);
		current = current->next;
	}
}

static void	ft_rotate_sphere(t_sphere *current, t_vector *rotate)
{
	while (current != NULL)
	{
		ft_rotate(&current->origin, rotate);
		current = current->next;
	}
}

void		ft_rotate_scene_p2(t_scene *scene, t_vector *rotate)
{
	ft_rotate_sphere(scene->mspheres, rotate);
	ft_rotate_cone(scene->mcones, rotate);
	ft_rotate_cylinder(scene->mcylinders, rotate);
	ft_rotate_plane(scene->mplanes, rotate);
}
