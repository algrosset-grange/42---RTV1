/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:43:30 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:43:38 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_init_raytracer(t_raytracer *raytracing)
{
	ft_inter_info_new_inter_info(&raytracing->tmpinterinfo);
	ft_inter_info_new_inter_info(&raytracing->closestinterinfo);
	raytracing->lightblocked = FALSE;
	raytracing->lighttoobjdist = 0.0f;
	raytracing->lighttointerdist = 0.0f;
}

static void	ft_verif_re_intersect(t_rt *rt, t_intersection_info *the_object)
{
	ft_re_intersect_plane(rt, the_object);
	if (rt->raytracing->lightblocked == FALSE)
		ft_re_intersect_sphere(rt, the_object);
	if (rt->raytracing->lightblocked == FALSE)
		ft_re_intersect_cylinder(rt, the_object);
	if (rt->raytracing->lightblocked == FALSE)
		ft_re_intersect_cone(rt, the_object);
}

static void	raytrace_p3(t_rt *rt, t_light *current_light,
	t_intersection_info *the_object)
{
	rt->raytracing->lightblocked = FALSE;
	ft_vect_equal_vect(&rt->ray->origin,
		&rt->raytracing->closestinterinfo.vec_mintersection);
	ft_vect_vect_less_vect(&rt->ray->direction,
		&current_light->origin, &rt->ray->origin);
	rt->raytracing->lighttoobjdist =
	ft_get_magnitude(&rt->ray->direction);
	if (rt->bol_shadow_draw == TRUE)
		ft_verif_re_intersect(rt, the_object);
	if (rt->raytracing->lightblocked == TRUE)
	{
		graduate_color(&rt->raytracing->finalcolor,
			&the_object->mmaterial->mdiffuse,
			&current_light->mcolor, 0.1);
	}
	else if (rt->bol_specular_draw == TRUE || rt->bol_diffuse_draw == TRUE)
		compute_color(rt, the_object,
			current_light, rt->ray);
	else
		ft_color_equal_color(&rt->raytracing->finalcolor,
			&the_object->mmaterial->mdiffuse);
}

static void	raytrace_p2(t_rt *rt)
{
	t_light				*current_light;
	t_intersection_info	the_object;

	ft_inter_equal_inter(&the_object,
		&rt->raytracing->closestinterinfo);
	current_light = rt->scene->mlights;
	while (current_light != NULL)
	{
		raytrace_p3(rt, current_light, &the_object);
		current_light = current_light->next;
	}
}

void		ft_raytrace(t_rt *rt)
{
	ft_init_raytracer(rt->raytracing);
	ft_intersect_sphere(rt);
	ft_intersect_plane(rt);
	ft_intersect_cylinder(rt);
	ft_intersect_cone(rt);
	if (rt->raytracing->closestinterinfo.mnode != NULL)
	{
		if (rt->bol_shadow_draw == FALSE && rt->bol_diffuse_draw == FALSE &&
			rt->bol_specular_draw == FALSE)
			ft_color_equal_color(&rt->raytracing->finalcolor,
				&rt->raytracing->closestinterinfo.mmaterial->mdiffuse);
		else
			raytrace_p2(rt);
	}
	ft_normalize_color(&rt->raytracing->finalcolor);
}
