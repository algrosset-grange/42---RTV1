/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_re_init_p1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:56:33 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 13:56:34 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_re_init_color(t_checkjson *check)
{
	check->annonce_color = NOT_DONE;
	check->color_r = 255;
	check->color_g = 255;
	check->color_b = 255;
}

void	ft_re_init_vect(t_checkjson *check)
{
	check->annonce_vector = NOT_DONE;
	check->vec_x = 0;
	check->vec_y = 0;
	check->vec_z = 0;
}

void	ft_re_init_scene(t_checkjson *check)
{
	check->scene_origin = NOT_DONE;
	check->scene_look_at = NOT_DONE;
	check->scene_translation = NOT_DONE;
	check->scene_rotation = NOT_DONE;
}

void	ft_re_init_material(t_checkjson *check)
{
	check->material = NOT_DONE;
	check->annonce_material = NOT_DONE;
	check->new_material = NOT_DONE;
	check->color = NOT_DONE;
}

void	ft_re_init_light(t_checkjson *check)
{
	check->light = NOT_DONE;
	check->annonce_light = NOT_DONE;
	check->new_light = NOT_DONE;
	check->translation = NOT_DONE;
	check->origin = NOT_DONE;
	check->color = NOT_DONE;
}
