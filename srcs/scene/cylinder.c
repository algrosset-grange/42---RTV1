/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:14:50 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 18:14:51 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_cylinder_init(t_cylinder *cyl)
{
	cyl->next = NULL;
	cyl->mmaterial = NULL;
}

t_cylinder	*ft_new_cylinder(const t_vector *orig, const t_vector *direc,
	const double radius, t_material *mat)
{
	t_cylinder *cyl;

	if ((cyl = ft_memalloc(sizeof(t_plane))) == NULL)
		return (NULL);
	ft_cylinder_init(cyl);
	ft_vect_equal_vect(&cyl->origin, orig);
	ft_vect_equal_vect(&cyl->direction, direc);
	ft_vect_n_vect(&cyl->rotation);
	cyl->mradius = radius;
	cyl->mmaterial = mat;
	return (cyl);
}

void		ft_cylinder_new_cylinder(t_cylinder *cyl, t_vector *orig_dir,
	double radius, t_material *mat)
{
	ft_cylinder_init(cyl);
	ft_vect_equal_vect(&cyl->origin, &orig_dir[0]);
	ft_vect_equal_vect(&cyl->direction, &orig_dir[1]);
	cyl->mradius = radius;
	cyl->mmaterial = mat;
}

static int	cyl_intersection_distance(t_intersection_info *intersectinfo,
	t_cylinder *cyl, t_ray *ray, t_cyl_cone_coef *coef)
{
	double		distance;
	double		t1;
	double		t2;
	double		t;
	t_vector	tmp;

	t1 = (-coef->b - sqrt(coef->d)) / (2.0 * coef->a);
	t2 = (-coef->b + sqrt(coef->d)) / (2.0 * coef->a);
	if (t1 > 0.000001)
		t = t1;
	else if (t2 > 0.000001)
		t = t2;
	else
		return (FALSE);
	ft_vect_vect_factor(&intersectinfo->vec_mintersection, &ray->origin, t,
		&ray->direction);
	ft_vect_vect_less_vect(&tmp, &ray->origin,
		&intersectinfo->vec_mintersection);
	distance = ft_get_magnitude(&tmp);
	intersectinfo->mnode = (void *)cyl;
	intersectinfo->mnodetype = CYLINDER;
	intersectinfo->mmaterial = cyl->mmaterial;
	intersectinfo->dist = distance;
	return (TRUE);
}

int			ft_cylinder_intersectsnode(t_cylinder *cyl, t_ray *ray,
	t_intersection_info *intersectinfo)
{
	t_cyl_cone_coef	coef;

	coef.dot_a = ft_dot_product(&ray->direction, &cyl->direction);
	ft_vect_vect_multi_double(&coef.sca_a, &cyl->direction, coef.dot_a);
	ft_vect_vect_less_vect(&coef.sub_a, &ray->direction, &coef.sca_a);
	coef.a = ft_dot_product(&coef.sub_a, &coef.sub_a);
	ft_vect_vect_less_vect(&coef.tmp, &ray->origin, &cyl->origin);
	coef.dot_b = ft_dot_product(&coef.tmp, &cyl->direction);
	ft_vect_vect_multi_double(&coef.sca_b, &cyl->direction, coef.dot_b);
	ft_vect_vect_less_vect(&coef.sub_b, &coef.tmp, &coef.sca_b);
	coef.b = 2 * ft_dot_product(&coef.sub_a, &coef.sub_b);
	coef.c = ft_dot_product(&coef.sub_b, &coef.sub_b) - cyl->mradius;
	coef.d = coef.b * coef.b - (4.0 * coef.a * coef.c);
	if (coef.d > 0)
		return (cyl_intersection_distance(intersectinfo, cyl, ray, &coef));
	return (FALSE);
}
