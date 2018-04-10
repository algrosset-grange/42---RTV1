/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:09:30 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 18:09:32 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_plane_init(t_plane *plane)
{
	plane->next = NULL;
	plane->mmaterial = NULL;
}

t_plane		*ft_new_plane(const t_vector *orig, const t_vector *direc,
	t_material *mat)
{
	t_plane *plan;

	if ((plan = ft_memalloc(sizeof(t_plane))) == NULL)
		return (NULL);
	ft_plane_init(plan);
	ft_vect_equal_vect(&plan->origin, orig);
	ft_vect_equal_vect(&plan->direction, direc);
	ft_vect_n_vect(&plan->rotation);
	plan->mmaterial = mat;
	return (plan);
}

void		ft_plane_new_plane(t_plane *plan, const t_vector *orig,
	const t_vector *direc, t_material *mat)
{
	ft_plane_init(plan);
	ft_vect_equal_vect(&plan->origin, orig);
	ft_vect_equal_vect(&plan->direction, direc);
	plan->mmaterial = mat;
}

int			ft_plane_intersectsnode(t_plane *plan, const t_ray *ray,
	t_intersection_info *tmpinterinfo)
{
	t_vector	xyz;
	double		a_b_t_d[4];

	a_b_t_d[1] = ft_dot_product(&plan->direction, &ray->direction);
	if (a_b_t_d[1] > 0.0001)
	{
		ft_vect_vect_less_vect(&xyz, &plan->origin, &ray->origin);
		a_b_t_d[0] = ft_dot_product(&plan->direction, &xyz);
		a_b_t_d[2] = a_b_t_d[0] / a_b_t_d[1];
		if (a_b_t_d[2] > 0.000001)
		{
			ft_vect_vect_factor(&tmpinterinfo->vec_mintersection, &ray->origin,
				a_b_t_d[2], &ray->direction);
			ft_vect_vect_less_vect(&xyz, &ray->origin,
				&tmpinterinfo->vec_mintersection);
			a_b_t_d[3] = ft_get_magnitude(&xyz);
			tmpinterinfo->mnode = (void *)plan;
			tmpinterinfo->mnodetype = PLANE;
			tmpinterinfo->mmaterial = plan->mmaterial;
			tmpinterinfo->dist = a_b_t_d[3];
			return (TRUE);
		}
	}
	return (FALSE);
}
