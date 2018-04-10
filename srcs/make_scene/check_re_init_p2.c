/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_re_init_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:56:40 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 13:56:41 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_re_init_sphere(t_checkjson *check)
{
	check->sphere = NOT_DONE;
	check->annonce_sphere = NOT_DONE;
	check->new_sphere = NOT_DONE;
	check->translation = NOT_DONE;
	check->origin = NOT_DONE;
	check->mat = NOT_DONE;
	check->num_mat = -1;
	check->radius = NOT_DONE;
	check->size_radius = 10.0;
}

void	ft_re_init_plane(t_checkjson *check)
{
	check->plane = NOT_DONE;
	check->annonce_plane = NOT_DONE;
	check->new_plane = NOT_DONE;
	check->origin = NOT_DONE;
	check->direction = NOT_DONE;
	check->translation = NOT_DONE;
	check->rotation = NOT_DONE;
	check->mat = NOT_DONE;
	check->num_mat = -1;
}

void	ft_re_init_cylinder(t_checkjson *check)
{
	check->cylinder = NOT_DONE;
	check->annonce_cylinder = NOT_DONE;
	check->new_cylinder = NOT_DONE;
	check->origin = NOT_DONE;
	check->direction = NOT_DONE;
	check->translation = NOT_DONE;
	check->rotation = NOT_DONE;
	check->mat = NOT_DONE;
	check->num_mat = -1;
	check->radius = NOT_DONE;
	check->size_radius = 10.0;
}

void	ft_re_init_cone(t_checkjson *check)
{
	check->cone = NOT_DONE;
	check->annonce_cone = NOT_DONE;
	check->new_cone = NOT_DONE;
	check->origin = NOT_DONE;
	check->direction = NOT_DONE;
	check->translation = NOT_DONE;
	check->rotation = NOT_DONE;
	check->mat = NOT_DONE;
	check->num_mat = -1;
	check->radius = NOT_DONE;
	check->size_radius = 10.0;
}
