/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:47:17 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:47:18 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**	pour spherre(0, 0, 0, rad = 21*21, preier contact en 427 , 666)
*/

void	ft_intersect_sphere(const t_rt *rt)
{
	t_sphere		*current_sph;

	current_sph = rt->scene->mspheres;
	while (current_sph != NULL)
	{
		if (ft_sphere_intersectsnode(current_sph, rt->ray,
			&rt->raytracing->tmpinterinfo) == TRUE)
		{
			if (rt->raytracing->tmpinterinfo.dist <
				rt->raytracing->closestinterinfo.dist)
			{
				ft_inter_equal_inter(&rt->raytracing->closestinterinfo,
					&rt->raytracing->tmpinterinfo);
			}
		}
		current_sph = current_sph->next;
	}
}

void	ft_intersect_plane(const t_rt *rt)
{
	t_plane			*current_plane;

	current_plane = rt->scene->mplanes;
	while (current_plane != NULL)
	{
		if (ft_plane_intersectsnode(current_plane, rt->ray,
			&rt->raytracing->tmpinterinfo) == TRUE)
		{
			if (rt->raytracing->tmpinterinfo.dist <
				rt->raytracing->closestinterinfo.dist)
				ft_inter_equal_inter(&rt->raytracing->closestinterinfo,
					&rt->raytracing->tmpinterinfo);
		}
		current_plane = current_plane->next;
	}
}

void	ft_intersect_cylinder(const t_rt *rt)
{
	t_cylinder		*current_cyl;

	current_cyl = rt->scene->mcylinders;
	while (current_cyl != NULL)
	{
		if (ft_cylinder_intersectsnode(current_cyl, rt->ray,
			&rt->raytracing->tmpinterinfo) == TRUE)
		{
			if (rt->raytracing->tmpinterinfo.dist <
				rt->raytracing->closestinterinfo.dist)
				ft_inter_equal_inter(&rt->raytracing->closestinterinfo,
					&rt->raytracing->tmpinterinfo);
		}
		current_cyl = current_cyl->next;
	}
}

void	ft_intersect_cone(const t_rt *rt)
{
	t_cone		*current_cone;

	current_cone = rt->scene->mcones;
	while (current_cone != NULL)
	{
		if (ft_cone_intersectsnode(current_cone, rt->ray,
			&rt->raytracing->tmpinterinfo) == TRUE)
		{
			if (rt->raytracing->tmpinterinfo.dist <
				rt->raytracing->closestinterinfo.dist)
				ft_inter_equal_inter(&rt->raytracing->closestinterinfo,
					&rt->raytracing->tmpinterinfo);
		}
		current_cone = current_cone->next;
	}
}
