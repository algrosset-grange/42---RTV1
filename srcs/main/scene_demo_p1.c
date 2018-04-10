/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_demo_p1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:45:43 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:45:44 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rappel :
** 1 = int
** 1.0 = double
** 1.0f = float
*/

#include "rtv1.h"

static int	scene_demo_mat_p2(t_scene *scene)
{
	t_material	*mat2;
	t_material	*mat3;
	t_material	*mat4;
	t_color		color_diffuse;

	if ((mat3 = ft_memalloc(sizeof(t_material))) == NULL)
		return (ft_error(ERROR_MALLOC));
	if ((mat4 = ft_memalloc(sizeof(t_material))) == NULL)
		return (ft_error(ERROR_MALLOC));
	mat2 = scene->mmaterials->next;
	ft_color_new_color(&color_diffuse, 0xFF, 0, 0xFF);
	ft_material_new_material(mat3, &color_diffuse);
	mat2->next = mat3;
	ft_color_new_color(&color_diffuse, 0xFF, 0xFF, 0);
	ft_material_new_material(mat4, &color_diffuse);
	mat3->next = mat4;
	return (NO_ERROR);
}

static int	scene_demo_mat_p1(t_scene *scene)
{
	t_color		color_diffuse;
	t_material	*mat1;
	t_material	*mat2;

	if ((mat1 = ft_memalloc(sizeof(t_material))) == NULL)
		return (ft_error(ERROR_MALLOC));
	if ((mat2 = ft_memalloc(sizeof(t_material))) == NULL)
		return (ft_error(ERROR_MALLOC));
	ft_color_new_color(&color_diffuse, 0x00, 0x00, 0xFF);
	ft_material_new_material(mat1, &color_diffuse);
	scene->mmaterials = mat1;
	ft_color_new_color(&color_diffuse, 0xFF, 0xFF, 0xFF);
	ft_material_new_material(mat2, &color_diffuse);
	mat1->next = mat2;
	return (scene_demo_mat_p2(scene));
}

static int	scene_demo_light(t_scene *scene)
{
	t_light		*light;
	t_light		*light2;
	t_vector	origin;
	t_color		mcolor;

	if ((light = ft_memalloc(sizeof(t_light))) == NULL)
		return (ft_error(ERROR_MALLOC));
	ft_vect_new_vect(&origin, 150.0f, 150.0f, -250.0f);
	ft_color_new_color(&mcolor, 0xFF, 0xFF, 0xFF);
	ft_light_new_light(light, &origin, &mcolor);
	scene->mlights = light;
	if ((light2 = ft_memalloc(sizeof(t_light))) == NULL)
		return (ft_error(ERROR_MALLOC));
	ft_vect_new_vect(&origin, -150.0f, 150.0f, -250.0f);
	ft_light_new_light(light2, &origin, &mcolor);
	light->next = light2;
	return (NO_ERROR);
}

int			ft_scene_demo(t_scene *scene)
{
	ft_vect_new_vect(&scene->origin, 0.0, 50.0, -250.0);
	ft_vect_new_vect(&scene->look_at, 0.0, 0.0, 0.0);
	if (scene_demo_mat_p1(scene) == ERROR_MALLOC)
		return (ERROR);
	if (scene_demo_light(scene) == ERROR_MALLOC)
		return (ERROR);
	return (ft_scene_demo_p2(scene));
}
