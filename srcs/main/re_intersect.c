/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:46:30 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:46:32 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_re_intersect_sphere(t_rt *rt, t_intersection_info *the_object)
{
	t_sphere	*current_sphere;

	current_sphere = rt->scene->mspheres;
	while (current_sphere != NULL)
	{
		if ((void *)current_sphere != the_object->mnode)
			if (ft_sphere_intersectsnode(current_sphere,
				rt->ray, &rt->raytracing->tmpinterinfo))
			{
				if (rt->raytracing->tmpinterinfo.dist <
					rt->raytracing->lighttoobjdist)
					rt->raytracing->lightblocked = TRUE;
				return ;
			}
		current_sphere = current_sphere->next;
	}
}

void	ft_re_intersect_plane(t_rt *rt, t_intersection_info *the_object)
{
	t_plane	*current_plane;

	current_plane = rt->scene->mplanes;
	while (current_plane != NULL)
	{
		if ((void *)current_plane != the_object->mnode)
			if (ft_plane_intersectsnode(current_plane,
				rt->ray, &rt->raytracing->tmpinterinfo))
			{
				if (rt->raytracing->tmpinterinfo.dist <
					rt->raytracing->lighttoobjdist)
					rt->raytracing->lightblocked = TRUE;
				return ;
			}
		current_plane = current_plane->next;
	}
}

void	ft_re_intersect_cylinder(t_rt *rt, t_intersection_info *the_object)
{
	t_cylinder	*current_cylinder;

	current_cylinder = rt->scene->mcylinders;
	while (current_cylinder != NULL)
	{
		if ((void *)current_cylinder != the_object->mnode)
			if (ft_cylinder_intersectsnode(current_cylinder,
				rt->ray, &rt->raytracing->tmpinterinfo))
			{
				if (rt->raytracing->tmpinterinfo.dist <
					rt->raytracing->lighttoobjdist)
					rt->raytracing->lightblocked = TRUE;
				return ;
			}
		current_cylinder = current_cylinder->next;
	}
}

void	ft_re_intersect_cone(t_rt *rt, t_intersection_info *the_object)
{
	t_cone	*current_cone;

	current_cone = rt->scene->mcones;
	while (current_cone != NULL)
	{
		if ((void *)current_cone != the_object->mnode)
			if (ft_cone_intersectsnode(current_cone,
				rt->ray, &rt->raytracing->tmpinterinfo))
			{
				if (rt->raytracing->tmpinterinfo.dist <
					rt->raytracing->lighttoobjdist)
					rt->raytracing->lightblocked = TRUE;
				return ;
			}
		current_cone = current_cone->next;
	}
}
