/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:58:54 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 13:58:56 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_continue(t_checkjson *check)
{
	if (check->material == IN_PROGRE ||
		check->sphere == IN_PROGRE ||
		check->plane == IN_PROGRE ||
		check->cylinder == IN_PROGRE ||
		check->cone == IN_PROGRE ||
		check->light == IN_PROGRE ||
		check->scene_origin == IN_PROGRE ||
		check->scene_look_at == IN_PROGRE ||
		check->scene_translation == IN_PROGRE)
		return (TRUE);
	return (FALSE);
}

static int	ft_make_continue(t_checkjson *check, t_rt *rt)
{
	if (check->material == IN_PROGRE)
		return (ft_check_part_material(check, rt->scene));
	if (check->sphere == IN_PROGRE)
		return (ft_check_part_sphere(check, rt->scene));
	if (check->plane == IN_PROGRE)
		return (ft_check_part_plane(check, rt->scene));
	if (check->cylinder == IN_PROGRE)
		return (ft_check_part_cylinder(check, rt->scene));
	if (check->cone == IN_PROGRE)
		return (ft_check_part_cone(check, rt->scene));
	if (check->light == IN_PROGRE)
		return (ft_check_part_light(check, rt->scene));
	if (check->scene_origin == IN_PROGRE ||
		check->scene_look_at == IN_PROGRE ||
		check->scene_translation == IN_PROGRE ||
		check->scene_rotation == IN_PROGRE)
		return (ft_check_part_scene(check, rt->scene));
	return (ft_check_error(check, ERROR));
}

int			ft_check(t_checkjson *check, t_rt *rt)
{
	if (ft_check_continue(check) == TRUE)
		return (ft_make_continue(check, rt));
	return (ft_check_part_p1(check, rt));
}
