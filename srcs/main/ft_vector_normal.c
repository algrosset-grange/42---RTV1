/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:49:07 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:49:08 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	http://hugi.scene.org/
**	online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
*/

static void	ft_vec_normal_sphere(t_vector *n_xyz,
	t_intersection_info *the_object, t_sphere *sphere)
{
	ft_vect_vect_less_vect(n_xyz, &the_object->vec_mintersection,
		&sphere->origin);
	ft_vect_normalize(n_xyz);
}

static void	ft_vec_normal_plane(t_vector *n_xyz, t_ray *ray, t_plane *plan)
{
	if (ft_dot_product(&ray->direction, &plan->direction) < 0)
		ft_vect_vect_negation(n_xyz, &plan->direction);
	else
		ft_vect_equal_vect(n_xyz, &plan->direction);
	ft_vect_normalize(n_xyz);
}

static void	ft_vec_normal_cylinder(t_vector *n_xyz,
	t_intersection_info *the_object, t_cylinder *cyl)
{
	t_vector	a;
	t_vector	b;

	ft_vect_vect_less_vect(&a, &the_object->vec_mintersection,
		&cyl->origin);
	ft_vect_vect_multi_double(&b, &cyl->direction,
		ft_dot_product(&a, &cyl->direction));
	ft_vect_vect_less_vect(n_xyz, &a, &b);
	ft_vect_normalize(n_xyz);
}

static void	ft_vec_normal_cone(t_vector *n_xyz, t_intersection_info *the_object,
	t_cone *cone)
{
	t_vector	a;
	t_vector	b;
	double		k;
	double		m;
	t_vector	c;

	ft_vect_vect_less_vect(&a, &the_object->vec_mintersection, &cone->origin);
	m = ft_dot_product(&a, &cone->direction);
	ft_vect_vect_multi_double(&b, &cone->direction, m);
	ft_vect_vect_add_vect(&c, &cone->origin, &b);
	ft_vect_vect_less_vect(&c, &the_object->vec_mintersection, &c);
	k = ft_get_magnitude(&c) / m;
	ft_vect_vect_multi_double(&b, &cone->direction, m * (1 + k * k));
	ft_vect_vect_less_vect(n_xyz, &a, &b);
	ft_vect_normalize(n_xyz);
}

void		ft_vector_normal(t_vector *n_xyz, t_intersection_info *the_object,
	t_ray *ray)
{
	if (the_object->mnodetype == SPHERE)
		ft_vec_normal_sphere(n_xyz, the_object,
			((t_sphere *)(the_object->mnode)));
	if (the_object->mnodetype == PLANE)
		ft_vec_normal_plane(n_xyz, ray,
			((t_plane *)(the_object->mnode)));
	if (the_object->mnodetype == CYLINDER)
		ft_vec_normal_cylinder(n_xyz, the_object,
			((t_cylinder *)(the_object->mnode)));
	if (the_object->mnodetype == CONE)
		ft_vec_normal_cone(n_xyz, the_object,
			((t_cone *)(the_object->mnode)));
}
