/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_scene_p1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:06:47 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:06:48 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_part_scene_p4(t_checkjson *check, t_scene *scene)
{
	if (check->scene_rotation == IN_PROGRE ||
		ft_match(check->line, "*\"rotation\"*:*"))
	{
		if (ft_rotation_scene(check, scene) == ERROR)
			return (ERROR);
		else
			return (NO_ERROR);
	}
	if (check->scene_translation == IN_PROGRE ||
		ft_match(check->line, "*\"translation\"*:*"))
	{
		if (ft_translation_scene(check, scene) == ERROR)
			return (ERROR);
		else
			return (NO_ERROR);
	}
	if (check->nb_bracket < 1 && check->nb_curly_bracket < 2)
	{
		ft_re_init_scene(check);
		return (NO_ERROR);
	}
	return (ft_check_error(check, ERROR_BAD_VAR));
}

static int	ft_check_part_scene_p3(t_checkjson *check, t_scene *scene)
{
	if (ft_match(check->line, "*\"height\"*:*"))
	{
		if (ft_check_uns_int(check, "*\"height\"*:*", &check->height)
			== NO_ERROR)
		{
			scene->pixelheight = check->height;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	if (ft_match(check->line, "*\"width\"*:*"))
	{
		if (ft_check_uns_int(check, "*\"width\"*:*", &check->width) == NO_ERROR)
		{
			scene->pixelwidth = check->width;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	return (ft_check_part_scene_p4(check, scene));
}

static int	ft_check_part_scene_p2(t_checkjson *check, t_scene *scene)
{
	if (check->scene_origin == IN_PROGRE ||
		ft_match(check->line, "*\"origin\"*:*"))
	{
		if (ft_origin_scene(check, scene) == ERROR)
			return (ERROR);
		else
			return (NO_ERROR);
	}
	if (check->scene_look_at == IN_PROGRE ||
		ft_match(check->line, "*\"look_at\"*:*"))
	{
		if (ft_look_at_scene(check, scene) == ERROR)
			return (ERROR);
		else
			return (NO_ERROR);
	}
	return (ft_check_part_scene_p3(check, scene));
}

int			ft_check_part_scene(t_checkjson *check, t_scene *scene)
{
	if (ft_check_part_scene_p2(check, scene) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}
