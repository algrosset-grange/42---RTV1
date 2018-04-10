/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:13:32 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 18:13:33 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_cone_init(t_cone *cone)
{
	cone->next = NULL;
	cone->mmaterial = NULL;
}

t_cone		*ft_new_cone(const t_vector *orig, const t_vector *direc,
	const double radius, t_material *mat)
{
	t_cone *cone;

	if ((cone = ft_memalloc(sizeof(t_plane))) == NULL)
		return (NULL);
	ft_cone_init(cone);
	ft_vect_equal_vect(&cone->origin, orig);
	ft_vect_equal_vect(&cone->direction, direc);
	ft_vect_n_vect(&cone->rotation);
	cone->mradius = radius;
	cone->mmaterial = mat;
	return (cone);
}

void		ft_cone_new_cone(t_cone *cone, t_vector *orig_dir,
	double radius, t_material *mat)
{
	ft_cone_init(cone);
	ft_vect_equal_vect(&cone->origin, &orig_dir[0]);
	ft_vect_equal_vect(&cone->direction, &orig_dir[1]);
	cone->mradius = radius;
	cone->mmaterial = mat;
}

static int	cone_intersection_distance(t_intersection_info *intersectinfo,
	t_cone *cone, t_ray *ray, t_cyl_cone_coef *coef)
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
	intersectinfo->mnode = (void *)cone;
	intersectinfo->mnodetype = CONE;
	intersectinfo->mmaterial = cone->mmaterial;
	intersectinfo->dist = distance;
	return (TRUE);
}

int			ft_cone_intersectsnode(t_cone *cone, t_ray *ray,
	t_intersection_info *intersectinfo)
{
	t_cyl_cone_coef	coef;

	coef.csq = cos(cone->mradius);
	coef.csq *= coef.csq;
	coef.ssq = sin(cone->mradius);
	coef.ssq *= coef.ssq;
	coef.dot_a = ft_dot_product(&ray->direction, &cone->direction);
	ft_vect_vect_multi_double(&coef.sca_a, &cone->direction, coef.dot_a);
	ft_vect_vect_less_vect(&coef.sub_a, &ray->direction, &coef.sca_a);
	coef.a = coef.csq * ft_dot_product(&coef.sub_a, &coef.sub_a);
	coef.a -= coef.ssq * coef.dot_a * coef.dot_a;
	ft_vect_vect_less_vect(&coef.tmp, &ray->origin, &cone->origin);
	coef.dot_b = ft_dot_product(&coef.tmp, &cone->direction);
	ft_vect_vect_multi_double(&coef.sca_b, &cone->direction, coef.dot_b);
	ft_vect_vect_less_vect(&coef.sub_b, &coef.tmp, &coef.sca_b);
	coef.b = 2.0 * coef.csq * ft_dot_product(&coef.sub_a, &coef.sub_b);
	coef.b -= 2.0 * coef.ssq * coef.dot_a * coef.dot_b;
	coef.c = coef.csq * ft_dot_product(&coef.sub_b, &coef.sub_b);
	coef.c -= coef.ssq * coef.dot_b * coef.dot_b;
	coef.d = coef.b * coef.b - (4.0 * coef.a * coef.c);
	if (coef.d > 0)
		return (cone_intersection_distance(intersectinfo, cone, ray, &coef));
	return (FALSE);
}
