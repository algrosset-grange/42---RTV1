/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_light_p1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:36:47 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:36:48 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_part_light_p3(t_checkjson *check, t_scene *scene,
	int bol_line)
{
	if (check->color == IN_PROGRE ||
	ft_match(check->line, "*\"color\"*:*"))
	{
		if (ft_color_light(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->nb_curly_bracket < 3)
	{
		ft_re_init_light(check);
		if (check->nb_bracket > 0)
			check->light = IN_PROGRE;
		bol_line = TRUE;
	}
	if (bol_line == TRUE)
		return (NO_ERROR);
	return (ft_check_error(check, ERROR_LIGNE_NO_USE));
}

static int	ft_check_part_light_p2(t_checkjson *check, t_scene *scene)
{
	int	bol_line;

	bol_line = FALSE;
	if (check->translation == IN_PROGRE ||
		ft_match(check->line, "*\"translation\"*:*"))
	{
		if (ft_translation_light(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->origin == IN_PROGRE ||
		ft_match(check->line, "*\"origin\"*:*"))
	{
		if (ft_origin_light(check, scene) != NO_ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	return (ft_check_part_light_p3(check, scene, bol_line));
}

static int	ft_check_part_light_p1(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_light(check, scene) == ERROR)
		return (ERROR);
	check->new_light = DONE;
	check->light = IN_PROGRE;
	return (NO_ERROR);
}

int			ft_check_part_light(t_checkjson *check, t_scene *scene)
{
	check->light = IN_PROGRE;
	if (check->new_light == NOT_DONE)
	{
		if (ft_check_part_light_p1(check, scene) == ERROR)
			return (ERROR);
	}
	return (ft_check_part_light_p2(check, scene));
}
