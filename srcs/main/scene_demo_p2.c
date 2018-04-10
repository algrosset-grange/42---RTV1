/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_demo_p2.c                                    :+:      :+:    :+:   */
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

static int	scene_demo_sphere(t_scene *scene)
{
	t_sphere	*sph;
	double		sph_radius;
	t_vector	origin;
	t_material	*mat1;

	if ((sph = ft_memalloc(sizeof(t_sphere))) == NULL)
		return (ft_error(ERROR_MALLOC));
	sph_radius = 21.0 * 21.0;
	mat1 = scene->mmaterials;
	ft_vect_new_vect(&origin, 0.0, 0.0, 0.0);
	ft_sphere_new_sphere(sph, &origin, sph_radius, mat1);
	scene->mspheres = sph;
	return (NO_ERROR);
}

static int	scene_demo_planes(t_scene *scene)
{
	t_plane		*plane;
	t_plane		*plane2;
	t_vector	vec_origin;
	t_vector	vec_direction;
	t_material	*mat2;

	mat2 = scene->mmaterials->next;
	if ((plane = ft_memalloc(sizeof(t_plane))) == NULL)
		return (ERROR_MALLOC);
	if ((plane2 = ft_memalloc(sizeof(t_plane))) == NULL)
		return (ERROR_MALLOC);
	ft_vect_new_vect(&vec_origin, 0.0, -21.0, 0.0);
	ft_vect_new_vect(&vec_direction, 0.0, -1.0, 0.0);
	ft_plane_new_plane(plane, &vec_origin, &vec_direction, mat2);
	ft_vect_normalize(&plane->direction);
	scene->mplanes = plane;
	ft_vect_new_vect(&vec_origin, 0.0, 0.0, 200.0);
	ft_vect_new_vect(&vec_direction, 0.0, 0.0, 1.0);
	ft_plane_new_plane(plane2, &vec_origin, &vec_direction, mat2);
	ft_vect_normalize(&plane2->direction);
	plane->next = plane2;
	return (NO_ERROR);
}

static int	scene_demo_cone(t_scene *scene)
{
	t_cone		*cone;
	t_vector	vec_origin_cone;
	t_vector	vec_direction_cone;
	t_vector	cone_origine_direction[2];
	double		cone_radius;

	if ((cone = ft_memalloc(sizeof(t_cone))) == NULL)
		return (ERROR_MALLOC);
	ft_vect_new_vect(&vec_origin_cone, 42.0, 21.0, 0.0);
	ft_vect_new_vect(&vec_direction_cone, 0.25, 1.0, 0.0);
	cone_radius = (5 * M_PI) / 180;
	cone_origine_direction[0] = vec_origin_cone;
	cone_origine_direction[1] = vec_direction_cone;
	ft_cone_new_cone(cone, cone_origine_direction, cone_radius,
		scene->mmaterials->next->next->next);
	ft_vect_normalize(&cone->direction);
	scene->mcones = cone;
	return (NO_ERROR);
}

static int	scene_demo_cylinder(t_scene *scene)
{
	t_cylinder	*cyl;
	t_vector	vec_origin_cyl;
	t_vector	vec_direction_cyl;
	t_vector	cyl_origine_direction[2];
	double		cyl_radius;

	if ((cyl = ft_memalloc(sizeof(t_cylinder))) == NULL)
		return (ERROR_MALLOC);
	ft_vect_new_vect(&vec_origin_cyl, -42.0, 0.0, 0.0);
	ft_vect_new_vect(&vec_direction_cyl, -0.25, 1.0, 0.0);
	cyl_radius = 100;
	cyl_origine_direction[0] = vec_origin_cyl;
	cyl_origine_direction[1] = vec_direction_cyl;
	ft_cylinder_new_cylinder(cyl, cyl_origine_direction, cyl_radius,
		scene->mmaterials->next->next);
	ft_vect_normalize(&cyl->direction);
	scene->mcylinders = cyl;
	return (NO_ERROR);
}

int			ft_scene_demo_p2(t_scene *scene)
{
	if (scene_demo_cone(scene) == ERROR_MALLOC)
		return (ERROR);
	if (scene_demo_cylinder(scene) == ERROR_MALLOC)
		return (ERROR);
	if (scene_demo_planes(scene) == ERROR_MALLOC)
		return (ERROR);
	if (scene_demo_sphere(scene) == ERROR_MALLOC)
		return (ERROR);
	return (NO_ERROR);
}
