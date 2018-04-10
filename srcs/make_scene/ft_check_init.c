/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:01:16 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 15:01:17 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_check_init_p4(t_checkjson *check)
{
	check->sphere = NOT_DONE;
	check->annonce_sphere = NOT_DONE;
	check->new_sphere = NOT_DONE;
	check->plane = NOT_DONE;
	check->annonce_plane = NOT_DONE;
	check->new_plane = NOT_DONE;
	check->cylinder = NOT_DONE;
	check->annonce_cylinder = NOT_DONE;
	check->new_cylinder = NOT_DONE;
	check->cone = NOT_DONE;
	check->annonce_cone = NOT_DONE;
	check->new_cone = NOT_DONE;
}

static void	ft_check_init_p3(t_checkjson *check)
{
	check->annonce_scene = NOT_DONE;
	check->scene_origin = NOT_DONE;
	check->scene_look_at = NOT_DONE;
	check->scene_translation = NOT_DONE;
	check->scene_rotation = NOT_DONE;
	check->material = NOT_DONE;
	check->annonce_material = NOT_DONE;
	check->new_material = NOT_DONE;
	check->light = NOT_DONE;
	check->annonce_light = NOT_DONE;
	check->new_light = NOT_DONE;
}

static void	ft_check_init_p2(t_checkjson *check)
{
	check->annonce_vector = NOT_DONE;
	check->origin = NOT_DONE;
	check->direction = NOT_DONE;
	check->translation = NOT_DONE;
	check->rotation = NOT_DONE;
	check->vec_x = 0.0;
	check->vec_y = 0.0;
	check->vec_z = 0.0;
	check->annonce_material = NOT_DONE;
	check->mat = NOT_DONE;
	check->num_mat = -1;
	check->radius = NOT_DONE;
	check->size_radius = 10.0;
	check->annonce_color = NOT_DONE;
	check->color = NOT_DONE;
	check->color_r = 255;
	check->color_g = 255;
	check->color_b = 255;
}

int			ft_check_init(t_checkjson *check, char *file)
{
	if ((check->fd = open(file, O_RDONLY)) == -1)
		return (ERROR_OPEN_FILE);
	check->file = file;
	check->line = NULL;
	check->nu_line = 0;
	check->nb_curly_bracket = 0;
	check->nb_bracket = 0;
	check->error = NO_ERROR;
	check->c_to_find = 0;
	ft_check_init_p2(check);
	ft_check_init_p3(check);
	ft_check_init_p4(check);
	return (NO_ERROR);
}
