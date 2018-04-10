/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_plane_p2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:09:25 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:09:25 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_direction_plane_p3(t_scene *scene)
{
	t_plane	*current;

	current = scene->mplanes;
	while (current->next != NULL)
		current = current->next;
	ft_vect_normalize(&current->direction);
}

static int	ft_direction_plane_p2(t_checkjson *check, t_scene *scene)
{
	t_plane	*current;

	current = scene->mplanes;
	while (current->next != NULL)
		current = current->next;
	if (ft_match(check->line, "*\"x\"*:*,*") &&
		ft_check_double(check, "*\"x\"*:*,*", &check->vec_x) == NO_ERROR)
	{
		current->direction.x = check->vec_x;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"y\"*:*,*") &&
		ft_check_double(check, "*\"y\"*:*,*", &check->vec_y) == NO_ERROR)
	{
		current->direction.y = check->vec_y;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"z\"*:*,*") &&
		ft_check_double(check, "*\"z\"*:*,*", &check->vec_z) == NO_ERROR)
	{
		current->direction.z = check->vec_z;
		return (NO_ERROR);
	}
	return (ERROR);
}

int			ft_direction_plane(t_checkjson *check, t_scene *scene)
{
	if (check->annonce_vector == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"direction\"*",
			&check->annonce_vector) == NO_ERROR)
		{
			if (check->annonce_plane == MULTI &&
			check->direction == DONE)
				if (ft_check_multi_plane(check, scene) == ERROR)
					return (ERROR);
			check->direction = IN_PROGRE;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	if (ft_direction_plane_p2(check, scene) == ERROR)
		return (ERROR);
	if (check->nb_curly_bracket < 4)
	{
		ft_re_init_vect(check);
		ft_direction_plane_p3(scene);
		check->direction = DONE;
	}
	return (NO_ERROR);
}

static int	ft_origin_plane_p2(t_checkjson *check, t_scene *scene)
{
	t_plane	*current;

	current = scene->mplanes;
	while (current->next != NULL)
		current = current->next;
	if (ft_match(check->line, "*\"x\"*:*,*") &&
		ft_check_double(check, "*\"x\"*:*,*", &check->vec_x) == NO_ERROR)
	{
		current->origin.x = check->vec_x;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"y\"*:*,*") &&
		ft_check_double(check, "*\"y\"*:*,*", &check->vec_y) == NO_ERROR)
	{
		current->origin.y = check->vec_y;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"z\"*:*,*") &&
		ft_check_double(check, "*\"z\"*:*,*", &check->vec_z) == NO_ERROR)
	{
		current->origin.z = check->vec_z;
		return (NO_ERROR);
	}
	return (ERROR);
}

int			ft_origin_plane(t_checkjson *check, t_scene *scene)
{
	if (check->annonce_vector == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"origin\"*",
			&check->annonce_vector) == NO_ERROR)
		{
			if (check->annonce_plane == MULTI &&
			check->origin == DONE)
				if (ft_check_multi_plane(check, scene) == ERROR)
					return (ERROR);
			check->origin = IN_PROGRE;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	if (ft_origin_plane_p2(check, scene) == ERROR)
		return (ERROR);
	if (check->nb_curly_bracket < 4)
	{
		ft_re_init_vect(check);
		check->origin = DONE;
	}
	return (NO_ERROR);
}
