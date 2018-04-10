/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:56:29 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 11:56:30 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		graduate_color(t_color *finalcolor, t_color *obj_rgb,
	t_color *light_rgb, double coef)
{
	finalcolor->r += obj_rgb->r * coef * (light_rgb->r / 0xFF);
	finalcolor->g += obj_rgb->g * coef * (light_rgb->g / 0xFF);
	finalcolor->b += obj_rgb->b * coef * (light_rgb->b / 0xFF);
	if (finalcolor->r > light_rgb->r)
		finalcolor->r = light_rgb->r;
	if (finalcolor->g > light_rgb->g)
		finalcolor->g = light_rgb->g;
	if (finalcolor->b > light_rgb->b)
		finalcolor->b = light_rgb->b;
}

static void	graduate_specular_color(t_color *finalcolor, t_color *light_color,
	double coef)
{
	finalcolor->r += light_color->r * coef;
	finalcolor->g += light_color->g * coef;
	finalcolor->b += light_color->b * coef;
	if (finalcolor->r > light_color->r)
		finalcolor->r = light_color->r;
	if (finalcolor->g > light_color->g)
		finalcolor->g = light_color->g;
	if (finalcolor->b > light_color->b)
		finalcolor->b = light_color->b;
}

/*
**	h
**	ttp://www.alrj.org/docs/3D/raytracer/raytracertutchap2.htm
*/

void		compute_color(t_rt *rt, t_intersection_info *the_object,
	t_light *light, t_ray *ray)
{
	t_vector	n_xyz;
	t_vector	l_xyz;
	double		sca;

	ft_vector_normal(&n_xyz, the_object, ray);
	ft_vect_vect_normalize(&l_xyz, &ray->direction);
	sca = ft_vect_cos_angle(&n_xyz, &l_xyz);
	if (sca < 0.0)
		sca = 0.0;
	if (rt->bol_diffuse_draw == TRUE)
		graduate_color(&rt->raytracing->finalcolor,
			&the_object->mmaterial->mdiffuse, &light->mcolor, sca * 0.9);
	if (the_object->mnodetype != PLANE && rt->bol_specular_draw == TRUE)
	{
		sca = pow(sca, 41);
		graduate_specular_color(&rt->raytracing->finalcolor,
			&light->mcolor, sca);
	}
}
