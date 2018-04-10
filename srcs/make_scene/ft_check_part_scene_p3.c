/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_scene_p3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:04:39 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:04:41 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_rotation_scene_p2(t_checkjson *check, t_scene *scene)
{
	if (ft_match(check->line, "*\"x\"*:*,*") &&
		ft_check_double(check, "*\"x\"*:*,*", &check->vec_x) == NO_ERROR)
	{
		scene->rotation.x = check->vec_x;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"y\"*:*,*") &&
		ft_check_double(check, "*\"y\"*:*,*", &check->vec_y) == NO_ERROR)
	{
		scene->rotation.y = check->vec_y;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"z\"*:*,*") &&
		ft_check_double(check, "*\"z\"*:*,*", &check->vec_z) == NO_ERROR)
	{
		scene->rotation.z = check->vec_z;
		return (NO_ERROR);
	}
	return (ERROR);
}

int			ft_rotation_scene(t_checkjson *check, t_scene *scene)
{
	if (check->annonce_vector == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"rotation\"*",
			&check->annonce_vector) == NO_ERROR)
		{
			check->scene_rotation = IN_PROGRE;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	if (check->nb_bracket < 3)
	{
		ft_re_init_vect(check);
		check->scene_rotation = DONE;
		return (NO_ERROR);
	}
	return (ft_rotation_scene_p2(check, scene));
}

static int	ft_translation_scene_p2(t_checkjson *check, t_scene *scene)
{
	if (ft_match(check->line, "*\"x\"*:*,*") &&
		ft_check_double(check, "*\"x\"*:*,*", &check->vec_x) == NO_ERROR)
	{
		scene->origin.x += check->vec_x;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"y\"*:*,*") &&
		ft_check_double(check, "*\"y\"*:*,*", &check->vec_y) == NO_ERROR)
	{
		scene->origin.y += check->vec_y;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"z\"*:*,*") &&
		ft_check_double(check, "*\"z\"*:*,*", &check->vec_z) == NO_ERROR)
	{
		scene->origin.z += check->vec_z;
		return (NO_ERROR);
	}
	return (ERROR);
}

int			ft_translation_scene(t_checkjson *check, t_scene *scene)
{
	if (check->annonce_vector == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"translation\"*",
			&check->annonce_vector) == NO_ERROR)
		{
			check->scene_translation = IN_PROGRE;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	if (check->nb_bracket < 3)
	{
		ft_re_init_vect(check);
		check->scene_translation = DONE;
		return (NO_ERROR);
	}
	return (ft_translation_scene_p2(check, scene));
}
