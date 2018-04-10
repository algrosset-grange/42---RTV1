/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_cone_p1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:58:13 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:58:14 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_part_cone_p4(t_checkjson *check, t_scene *scene,
	int bol_line)
{
	if (ft_match(check->line, "*\"num_material\"*:*") &&
		ft_check_uns_int(check, "*\"num_material\"*:*",
			&check->num_mat) == NO_ERROR)
	{
		if (ft_check_add_mat_cone(check, scene) == ERROR)
			return (ERROR);
		check->mat = DONE;
		bol_line = TRUE;
	}
	if (check->nb_curly_bracket < 3)
	{
		ft_re_init_cone(check);
		if (check->nb_bracket > 0)
			check->cone = IN_PROGRE;
		bol_line = TRUE;
	}
	if (bol_line == TRUE)
		return (NO_ERROR);
	return (ft_check_error(check, ERROR_LIGNE_NO_USE));
}

static int	ft_check_part_cone_p3(t_checkjson *check, t_scene *scene,
	int bol_line)
{
	if (check->direction == IN_PROGRE ||
		ft_match(check->line, "*\"direction\"*:*"))
	{
		if (ft_direction_cone(check, scene) == ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (ft_match(check->line, "*\"radius\"*:*") &&
		ft_check_uns_double(check, "*\"radius\"*:*",
			&(check->size_radius)) == NO_ERROR)
	{
		if (ft_radius_cone(check, scene) == ERROR)
			return (ERROR);
		check->radius = DONE;
		bol_line = TRUE;
	}
	if (check->origin == IN_PROGRE ||
		ft_match(check->line, "*\"origin\"*:*"))
	{
		if (ft_origin_cone(check, scene) == ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	return (ft_check_part_cone_p4(check, scene, bol_line));
}

static int	ft_check_part_cone_p2(t_checkjson *check, t_scene *scene)
{
	int	bol_line;

	bol_line = FALSE;
	if (check->translation == IN_PROGRE ||
		ft_match(check->line, "*\"translation\"*:*"))
	{
		if (ft_translation_cone(check, scene) == ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->rotation == IN_PROGRE ||
		ft_match(check->line, "*\"rotation\"*:*"))
	{
		if (ft_rotation_cone(check, scene) == ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	return (ft_check_part_cone_p3(check, scene, bol_line));
}

static int	ft_check_part_cone_p1(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_cone(check, scene) == ERROR)
		return (ERROR);
	check->new_cone = DONE;
	check->cone = IN_PROGRE;
	return (NO_ERROR);
}

int			ft_check_part_cone(t_checkjson *check, t_scene *scene)
{
	check->cone = IN_PROGRE;
	if (check->new_cone == NOT_DONE)
	{
		if (ft_check_part_cone_p1(check, scene) == ERROR)
			return (ERROR);
	}
	return (ft_check_part_cone_p2(check, scene));
}
