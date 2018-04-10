/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_p1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:26:24 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:26:26 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_part_p5(t_checkjson *check, t_rt *rt)
{
	if (ft_match(check->line, "*\"width\"*") ||
		ft_match(check->line, "*\"height\"*"))
	{
		if (ft_check_part_scene(check, rt->scene) == ERROR)
			return (ERROR);
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"transistion\"*"))
	{
		if (ft_check_part_scene(check, rt->scene) == ERROR)
			return (ERROR);
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"rotation\"*"))
	{
		if (ft_check_part_scene(check, rt->scene) == ERROR)
			return (ERROR);
		return (NO_ERROR);
	}
	return (ft_check_error(check, ERROR_ANNONCE));
}

static int	ft_check_part_p4(t_checkjson *check, t_rt *rt)
{
	if (ft_match(check->line, "*\"scene\"*"))
	{
		if (ft_check_annonce_scene(check) == ERROR)
			return (ERROR);
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"origin\"*"))
	{
		if (ft_check_part_scene(check, rt->scene) == ERROR)
			return (ERROR);
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"look_at\"*"))
	{
		if (ft_check_part_scene(check, rt->scene) == ERROR)
			return (ERROR);
		return (NO_ERROR);
	}
	return (ft_check_part_p5(check, rt));
}

static int	ft_check_part_p3(t_checkjson *check, t_rt *rt)
{
	if (ft_match(check->line, "*\"material\"*"))
	{
		if (ft_check_annonce_material(check))
		{
			check->material = IN_PROGRE;
			return (NO_ERROR);
		}
		return (ERROR);
	}
	if (ft_match(check->line, "*\"light\"*"))
	{
		if (ft_check_annonce_light(check))
		{
			check->light = IN_PROGRE;
			return (NO_ERROR);
		}
		return (ERROR);
	}
	return (ft_check_part_p4(check, rt));
}

static int	ft_check_part_p2(t_checkjson *check, t_rt *rt)
{
	if (ft_match(check->line, "*\"cylinder\"*"))
	{
		if (ft_check_annonce_cylinder(check))
		{
			check->cylinder = IN_PROGRE;
			return (NO_ERROR);
		}
		return (ERROR);
	}
	if (ft_match(check->line, "*\"cone\"*"))
	{
		if (ft_check_annonce_cone(check))
		{
			check->cone = IN_PROGRE;
			return (NO_ERROR);
		}
		return (ERROR);
	}
	return (ft_check_part_p3(check, rt));
}

int			ft_check_part_p1(t_checkjson *check, t_rt *rt)
{
	if (ft_match(check->line, "*\"sphere\"*"))
	{
		if (ft_check_annonce_sphere(check) != ERROR)
		{
			check->sphere = IN_PROGRE;
			return (NO_ERROR);
		}
		return (ERROR);
	}
	if (ft_match(check->line, "*\"plane\"*"))
	{
		if (ft_check_annonce_plane(check))
		{
			check->plane = IN_PROGRE;
			return (NO_ERROR);
		}
		return (ERROR);
	}
	return (ft_check_part_p2(check, rt));
}
