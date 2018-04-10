/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:58:19 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 17:58:30 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_scene_init(t_scene *scene)
{
	ft_vect_n_vect(&scene->origin);
	ft_vect_n_vect(&scene->look_at);
	ft_vect_n_vect(&scene->orientation_u);
	ft_vect_n_vect(&scene->orientation_v);
	scene->pixelwidth = 0;
	scene->pixelheight = 0;
	scene->orientation_u.x = 1.f;
	scene->orientation_v.y = 1.f;
	scene->mmaterials = NULL;
	scene->mlights = NULL;
	scene->mspheres = NULL;
	scene->mplanes = NULL;
}
