/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_plane_p3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:09:30 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:09:31 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_rotation_plane_p3(t_scene *scene)
{
	t_plane	*current;

	current = scene->mplanes;
	while (current->next != NULL)
		current = current->next;
	ft_rotate(&current->direction, &current->rotation);
}

static int	ft_rotation_plane_p2(t_checkjson *check, t_scene *scene)
{
	t_plane	*current;

	current = scene->mplanes;
	while (current->next != NULL)
		current = current->next;
	if (ft_match(check->line, "*\"x\"*:*,*") &&
		ft_check_double(check, "*\"x\"*:*,*", &check->vec_x) == NO_ERROR)
	{
		current->rotation.x = check->vec_x;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"y\"*:*,*") &&
		ft_check_double(check, "*\"y\"*:*,*", &check->vec_y) == NO_ERROR)
	{
		current->rotation.y = check->vec_y;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"z\"*:*,*") &&
		ft_check_double(check, "*\"z\"*:*,*", &check->vec_z) == NO_ERROR)
	{
		current->rotation.z = check->vec_z;
		return (NO_ERROR);
	}
	return (ERROR);
}

int			ft_rotation_plane(t_checkjson *check, t_scene *scene)
{
	if (check->annonce_vector == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"rotation\"*",
			&check->annonce_vector) == NO_ERROR)
		{
			if (check->annonce_plane == MULTI &&
			check->rotation == DONE)
				if (ft_check_multi_plane(check, scene) == ERROR)
					return (ERROR);
			check->rotation = IN_PROGRE;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	if (ft_rotation_plane_p2(check, scene) == ERROR)
		return (ERROR);
	if (check->nb_curly_bracket < 4)
	{
		ft_re_init_vect(check);
		ft_rotation_plane_p3(scene);
		check->rotation = DONE;
	}
	return (NO_ERROR);
}

static int	ft_translation_plane_p2(t_checkjson *check, t_scene *scene)
{
	t_plane	*current;

	current = scene->mplanes;
	while (current->next != NULL)
		current = current->next;
	if (ft_match(check->line, "*\"x\"*:*,*") &&
		ft_check_double(check, "*\"x\"*:*,*", &check->vec_x) == NO_ERROR)
	{
		current->origin.x += check->vec_x;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"y\"*:*,*") &&
		ft_check_double(check, "*\"y\"*:*,*", &check->vec_y) == NO_ERROR)
	{
		current->origin.y += check->vec_y;
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"z\"*:*,*") &&
		ft_check_double(check, "*\"z\"*:*,*", &check->vec_z) == NO_ERROR)
	{
		current->origin.z += check->vec_z;
		return (NO_ERROR);
	}
	return (ERROR);
}

int			ft_translation_plane(t_checkjson *check, t_scene *scene)
{
	if (check->annonce_vector == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"translation\"*",
			&check->annonce_vector) == NO_ERROR)
		{
			if (check->annonce_plane == MULTI &&
			check->translation == DONE)
				if (ft_check_multi_plane(check, scene) == ERROR)
					return (ERROR);
			check->translation = IN_PROGRE;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	if (ft_translation_plane_p2(check, scene) == ERROR)
		return (ERROR);
	if (check->nb_curly_bracket < 4)
	{
		ft_re_init_vect(check);
		check->translation = DONE;
	}
	return (NO_ERROR);
}
