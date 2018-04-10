/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_scene_p1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:29:13 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:29:14 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_rotate_light(t_light *current, t_vector *rotate)
{
	while (current != NULL)
	{
		ft_rotate(&current->origin, rotate);
		current = current->next;
	}
}

static void	ft_rotate_scene_origin(t_scene *scene, t_vector *rotate)
{
	ft_rotate(&scene->origin, rotate);
}

void		ft_rotate_scene_p1(t_scene *scene)
{
	t_vector	rotate;
	t_vector	direction;

	ft_vect_vect_less_vect(&direction, &scene->look_at, &scene->origin);
	ft_vect_normalize(&direction);
	if (direction.z < 0)
	{
		rotate.x = 0;
		rotate.y = 180;
		rotate.z = 0;
		ft_rotate_scene_origin(scene, &rotate);
		ft_rotate_light(scene->mlights, &rotate);
		ft_rotate_scene_p2(scene, &rotate);
		ft_vect_vect_less_vect(&direction, &scene->look_at, &scene->origin);
		ft_vect_normalize(&direction);
	}
	rotate.x = ft_asin_deg(direction.y);
	rotate.y = -ft_asin_deg(direction.x);
	rotate.z = 0;
	ft_rotate_scene_origin(scene, &rotate);
	ft_rotate_light(scene->mlights, &rotate);
	ft_rotate_scene_p2(scene, &rotate);
}
