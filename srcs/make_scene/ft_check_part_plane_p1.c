/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_plane_p1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:09:19 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:09:20 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_part_plane_p4(t_checkjson *check, t_scene *scene,
	int bol_line)
{
	if (ft_match(check->line, "*\"num_material\"*:*") &&
		ft_check_uns_int(check, "*\"num_material\"*:*", &check->num_mat) ==
		NO_ERROR)
	{
		if (ft_check_add_mat_plane(check, scene) != NO_ERROR)
			return (ERROR);
		check->mat = DONE;
		bol_line = TRUE;
	}
	if (check->nb_curly_bracket < 3)
	{
		ft_re_init_plane(check);
		if (check->nb_bracket > 0)
			check->plane = IN_PROGRE;
		bol_line = TRUE;
	}
	if (bol_line == TRUE)
		return (NO_ERROR);
	return (ERROR);
}

static int	ft_check_part_plane_p3(t_checkjson *check, t_scene *scene,
	int bol_line)
{
	if (check->origin == IN_PROGRE ||
		ft_match(check->line, "*\"origin\"*:*"))
	{
		if (ft_origin_plane(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->direction == IN_PROGRE ||
	ft_match(check->line, "*\"direction\"*:*"))
	{
		if (ft_direction_plane(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	return (ft_check_part_plane_p4(check, scene, bol_line));
}

static int	ft_check_part_plane_p2(t_checkjson *check, t_scene *scene)
{
	int	bol_line;

	bol_line = FALSE;
	if (check->translation == IN_PROGRE ||
		ft_match(check->line, "*\"translation\"*:*"))
	{
		if (ft_translation_plane(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->rotation == IN_PROGRE ||
		ft_match(check->line, "*\"rotation\"*:*"))
	{
		if (ft_rotation_plane(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	return (ft_check_part_plane_p3(check, scene, bol_line));
}

static int	ft_check_part_plane_p1(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_plane(check, scene) == ERROR)
		return (ERROR);
	check->new_plane = DONE;
	check->plane = IN_PROGRE;
	return (NO_ERROR);
}

int			ft_check_part_plane(t_checkjson *check, t_scene *scene)
{
	check->plane = IN_PROGRE;
	if (check->new_plane == NOT_DONE)
	{
		if (ft_check_part_plane_p1(check, scene) == ERROR)
			return (ERROR);
	}
	return (ft_check_part_plane_p2(check, scene));
}
