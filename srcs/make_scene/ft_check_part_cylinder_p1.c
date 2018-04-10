/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_cylinder_p1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:44:53 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:44:55 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_part_cylinder_p4(t_checkjson *check, t_scene *scene,
	int bol_line)
{
	if (check->origin == IN_PROGRE ||
		ft_match(check->line, "*\"origin\"*:*"))
	{
		if (ft_origin_cylinder(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->direction == IN_PROGRE ||
		ft_match(check->line, "*\"direction\"*:*"))
	{
		if (ft_direction_cylinder(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->nb_curly_bracket < 3)
	{
		ft_re_init_cylinder(check);
		if (check->nb_bracket > 0)
			check->cylinder = IN_PROGRE;
		bol_line = TRUE;
	}
	if (bol_line == TRUE)
		return (NO_ERROR);
	return (ft_check_error(check, ERROR_LIGNE_NO_USE));
}

static int	ft_check_part_cylinder_p3(t_checkjson *check, t_scene *scene,
	int bol_line)
{
	if (ft_match(check->line, "*\"num_material\"*:*") &&
		ft_check_uns_int(check, "*\"num_material\"*:*", &check->num_mat)
		== NO_ERROR)
	{
		if (ft_check_add_mat_cylinder(check, scene) == ERROR)
			return (ERROR);
		check->mat = DONE;
		bol_line = TRUE;
	}
	if (ft_match(check->line, "*\"radius\"*:*") &&
		ft_check_uns_double(check, "*\"radius\"*:*",
			&(check->size_radius)) == NO_ERROR)
	{
		if (ft_radius_cylinder(check, scene) == ERROR)
			return (ERROR);
		check->radius = DONE;
		bol_line = TRUE;
	}
	return (ft_check_part_cylinder_p4(check, scene, bol_line));
}

static int	ft_check_part_cylinder_p2(t_checkjson *check, t_scene *scene)
{
	int	bol_line;

	bol_line = FALSE;
	if (check->translation == IN_PROGRE ||
		ft_match(check->line, "*\"translation\"*:*"))
	{
		if (ft_translation_cylinder(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->rotation == IN_PROGRE ||
		ft_match(check->line, "*\"rotation\"*:*"))
	{
		if (ft_rotation_cylinder(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	return (ft_check_part_cylinder_p3(check, scene, bol_line));
}

static int	ft_check_part_cylinder_p1(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_cylinder(check, scene) == ERROR)
		return (ERROR);
	check->new_cylinder = DONE;
	check->cylinder = IN_PROGRE;
	return (NO_ERROR);
}

int			ft_check_part_cylinder(t_checkjson *check, t_scene *scene)
{
	check->cylinder = IN_PROGRE;
	if (check->new_cylinder == NOT_DONE)
	{
		if (ft_check_part_cylinder_p1(check, scene) == ERROR)
			return (ERROR);
	}
	return (ft_check_part_cylinder_p2(check, scene));
}
