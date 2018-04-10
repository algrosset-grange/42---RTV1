/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_material_p1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:28:21 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:28:23 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_part_material_p2(t_checkjson *check, t_scene *scene)
{
	int	bol_line;

	bol_line = FALSE;
	if (check->color == IN_PROGRE ||
	ft_match(check->line, "*\"color\"*:*"))
	{
		if (ft_color_material(check, scene) == ERROR)
			return (ERROR);
		bol_line = TRUE;
	}
	if (check->nb_curly_bracket < 3)
	{
		ft_re_init_material(check);
		if (check->nb_bracket > 0)
			check->material = IN_PROGRE;
		bol_line = TRUE;
	}
	if (bol_line == TRUE)
		return (NO_ERROR);
	return (ft_check_error(check, ERROR_LIGNE_NO_USE));
}

static int	ft_check_part_material_p1(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_material(check, scene) == ERROR)
		return (ERROR);
	check->new_material = DONE;
	check->material = IN_PROGRE;
	return (NO_ERROR);
}

int			ft_check_part_material(t_checkjson *check, t_scene *scene)
{
	check->material = IN_PROGRE;
	if (check->new_material == NOT_DONE)
	{
		if (ft_check_part_material_p1(check, scene) == ERROR)
			return (ERROR);
	}
	return (ft_check_part_material_p2(check, scene));
}
