/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:57:03 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 17:57:04 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere		*ft_new_sphere(t_vector *center, double radius, t_material *mat)
{
	t_sphere *sphere;

	if ((sphere = ft_memalloc(sizeof(t_sphere))) == NULL)
		return (NULL);
	sphere->next = NULL;
	sphere->mmaterial = mat;
	ft_vect_equal_vect(&sphere->origin, center);
	sphere->mradius = radius;
	return (sphere);
}

void			ft_sphere_new_sphere(t_sphere *sphere, t_vector *center,
	double radius, t_material *mat)
{
	sphere->next = NULL;
	sphere->mmaterial = mat;
	ft_vect_equal_vect(&sphere->origin, center);
	sphere->mradius = radius;
}

static int		sphere_intersection_distance(t_intersection_info *tmpinterinfo,
	t_sphere *sphere, const t_ray *ray, double *a_b_c_d)
{
	double		distance;
	t_vector	xyz;
	double		t;

	if ((t = (-a_b_c_d[1] - sqrt(a_b_c_d[3])) / (2.0 * a_b_c_d[0]))
		<= 0.000001)
		if ((t = (-a_b_c_d[1] + sqrt(a_b_c_d[3])) / (2.0 * a_b_c_d[0]))
		<= 0.000001)
			return (FALSE);
	ft_vect_vect_factor(&tmpinterinfo->vec_mintersection, &ray->origin, t,
		&ray->direction);
	ft_vect_vect_less_vect(&xyz, &ray->origin,
		&tmpinterinfo->vec_mintersection);
	distance = ft_get_magnitude(&xyz);
	tmpinterinfo->dist = distance;
	tmpinterinfo->mnode = (void *)sphere;
	tmpinterinfo->mnodetype = SPHERE;
	tmpinterinfo->mmaterial = sphere->mmaterial;
	return (TRUE);
}

int				ft_sphere_intersectsnode(t_sphere *sphere, const t_ray *ray,
	t_intersection_info *tmpinterinfo)
{
	t_vector	xyz;
	double		a_b_c_d[4];

	ft_vect_vect_less_vect(&xyz, &ray->origin, &sphere->origin);
	a_b_c_d[0] = ft_get_square_length(&ray->direction);
	a_b_c_d[1] = 2.0 * ft_dot_product(&ray->direction, &xyz);
	a_b_c_d[2] = ft_get_square_length(&xyz) - sphere->mradius;
	a_b_c_d[3] = a_b_c_d[1] * a_b_c_d[1] - (4.0 * a_b_c_d[0] * a_b_c_d[2]);
	if (a_b_c_d[3] > 0)
	{
		return (sphere_intersection_distance(tmpinterinfo, sphere,
			ray, a_b_c_d));
	}
	return (FALSE);
}
