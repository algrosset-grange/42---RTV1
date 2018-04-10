/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_light_p3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:36:59 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:37:01 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_check_multi_light(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_light(check, scene) == ERROR)
		return (ERROR);
	check->light = IN_PROGRE;
	check->annonce_light = MULTI;
	return (NO_ERROR);
}

static int	ft_color_light_p3(t_checkjson *check, t_light *current)
{
	if (ft_match(check->line, "*\"r\"*:*,*") &&
		ft_check_int(check, "*\"r\"*:*,*", &check->color_r) == NO_ERROR)
	{
		current->mcolor.r = check->color_r;
		ft_normalize_color(&current->mcolor);
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"g\"*:*,*") &&
		ft_check_int(check, "*\"g\"*:*,*", &check->color_g) == NO_ERROR)
	{
		current->mcolor.g = check->color_g;
		ft_normalize_color(&current->mcolor);
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"b\"*:*,*") &&
		ft_check_int(check, "*\"b\"*:*,*", &check->color_b) == NO_ERROR)
	{
		current->mcolor.b = check->color_b;
		ft_normalize_color(&current->mcolor);
		return (NO_ERROR);
	}
	return (ERROR);
}

static int	ft_color_light_p2(t_checkjson *check, t_scene *scene)
{
	t_light	*current;

	current = scene->mlights;
	while (current->next != NULL)
		current = current->next;
	return (ft_color_light_p3(check, current));
}

int			ft_color_light(t_checkjson *check, t_scene *scene)
{
	if (check->annonce_color == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"color\"*",
			&check->annonce_color) == NO_ERROR)
		{
			if (check->annonce_light == MULTI &&
			check->color == DONE)
				if (ft_make_new_light(check, scene) == ERROR)
					return (ERROR);
			check->color = IN_PROGRE;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	if (ft_color_light_p2(check, scene) == ERROR)
		return (ERROR);
	if (check->nb_curly_bracket < 4)
	{
		ft_re_init_color(check);
		check->color = DONE;
	}
	return (NO_ERROR);
}

int			ft_make_new_light(t_checkjson *check, t_scene *scene)
{
	t_light		*current;
	t_vector	vec;
	t_color		color;

	ft_vect_new_vect(&vec, 0.0, 10.0, -10.0);
	ft_color_new_color(&color, 255, 255, 255);
	current = scene->mlights;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		if ((current->next = ft_new_light(&vec, &color)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = current->next;
	}
	else
	{
		if ((scene->mlights = ft_new_light(&vec, &color)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = scene->mlights;
	}
	ft_re_init_light(check);
	return (NO_ERROR);
}
