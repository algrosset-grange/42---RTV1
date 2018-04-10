/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_scene_p2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:07:15 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:07:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_look_at_scene_p2(t_checkjson *check, t_scene *scene)
{
	if (ft_match(check->line, "*\"x\"*:*,*") &&
		ft_check_double(check, "*\"x\"*:*,*", &check->vec_x) == NO_ERROR)
	{
		scene->look_at.x = check->vec_x;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"y\"*:*,*") &&
	ft_check_double(check, "*\"y\"*:*,*", &check->vec_y) == NO_ERROR)
	{
		scene->look_at.y = check->vec_y;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"z\"*:*,*") &&
		ft_check_double(check, "*\"z\"*:*,*", &check->vec_z) == NO_ERROR)
	{
		scene->look_at.z = check->vec_z;
		return (NO_ERROR);
	}
	return (ERROR);
}

int			ft_look_at_scene(t_checkjson *check, t_scene *scene)
{
	check->scene_look_at = IN_PROGRE;
	if (check->annonce_vector == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"look_at\"*",
			&check->annonce_vector) == NO_ERROR)
			return (NO_ERROR);
		else
			return (ERROR);
	}
	if (ft_look_at_scene_p2(check, scene) == ERROR)
		return (ERROR);
	if (check->nb_curly_bracket < 3)
	{
		ft_re_init_vect(check);
		check->scene_look_at = DONE;
	}
	return (NO_ERROR);
}

static int	ft_origin_scene_p2(t_checkjson *check, t_scene *scene)
{
	if (ft_match(check->line, "*\"x\"*:*,*") &&
		ft_check_double(check, "*\"x\"*:*,*", &check->vec_x) == NO_ERROR)
	{
		scene->origin.x = check->vec_x;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"y\"*:*,*") &&
		ft_check_double(check, "*\"y\"*:*,*", &check->vec_y) == NO_ERROR)
	{
		scene->origin.y = check->vec_y;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"z\"*:*,*") &&
		ft_check_double(check, "*\"z\"*:*,*", &check->vec_z) == NO_ERROR)
	{
		scene->origin.z = check->vec_z;
		return (NO_ERROR);
	}
	return (ERROR);
}

int			ft_origin_scene(t_checkjson *check, t_scene *scene)
{
	check->scene_origin = IN_PROGRE;
	if (check->annonce_vector == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"origin\"*",
			&check->annonce_vector) == NO_ERROR)
			return (NO_ERROR);
		else
			return (ERROR);
	}
	if (ft_origin_scene_p2(check, scene) == ERROR)
		return (ERROR);
	if (check->nb_curly_bracket < 3)
	{
		ft_re_init_vect(check);
		check->scene_origin = DONE;
	}
	return (NO_ERROR);
}
