/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_sphere_p1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:05:22 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:05:23 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_part_sphere_p4(t_checkjson *check, int bol_line)
{
	if (check->nb_curly_bracket < 3)
	{
		ft_re_init_sphere(check);
		if (check->nb_bracket > 0)
			check->sphere = IN_PROGRE;
		bol_line = TRUE;
	}
	if (bol_line == TRUE)
		return (NO_ERROR);
	return (ft_check_error(check, ERROR_LIGNE_NO_USE));
}

static int	ft_check_part_sphere_p3(t_checkjson *check, t_scene *scene,
	int bol_line)
{
	if (ft_match(check->line, "*\"num_material\"*:*") &&
		ft_check_uns_int(check, "*\"num_material\"*:*",
			&check->num_mat) == NO_ERROR)
	{
		if (ft_check_add_mat_sphere(check, scene) == ERROR)
			return (ERROR);
		check->mat = DONE;
		bol_line = TRUE;
	}
	if (ft_match(check->line, "*\"radius\"*:*") &&
		ft_check_uns_double(check, "*\"radius\"*:*",
			&(check->size_radius)) == NO_ERROR)
	{
		if (ft_radius_sphere(check, scene) == ERROR)
			return (ERROR);
		check->radius = DONE;
		bol_line = TRUE;
	}
	return (ft_check_part_sphere_p4(check, bol_line));
}

static int	ft_check_part_sphere_p2(t_checkjson *check, t_scene *scene)
{
	int	bol_line;

	bol_line = FALSE;
	if (check->translation == IN_PROGRE ||
		ft_match(check->line, "*\"translation\"*:*"))
	{
		if (ft_translation_sphere(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->origin == IN_PROGRE ||
		ft_match(check->line, "*\"origin\"*:*"))
	{
		if (ft_origin_sphere(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	return (ft_check_part_sphere_p3(check, scene, bol_line));
}

static int	ft_check_part_sphere_p1(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_sphere(check, scene) == ERROR)
		return (ERROR);
	check->new_sphere = DONE;
	check->sphere = IN_PROGRE;
	return (NO_ERROR);
}

int			ft_check_part_sphere(t_checkjson *check, t_scene *scene)
{
	check->sphere = IN_PROGRE;
	if (check->new_sphere == NOT_DONE)
	{
		if (ft_check_part_sphere_p1(check, scene) == ERROR)
			return (ERROR);
	}
	return (ft_check_part_sphere_p2(check, scene));
}
