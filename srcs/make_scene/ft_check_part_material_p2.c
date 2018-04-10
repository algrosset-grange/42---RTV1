/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_material_p2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:28:27 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:28:28 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_check_multi_material(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_material(check, scene) == ERROR)
		return (ERROR);
	check->material = IN_PROGRE;
	check->annonce_material = MULTI;
	return (NO_ERROR);
}

static int	ft_color_material_p3(t_checkjson *check, t_material *current)
{
	if (ft_match(check->line, "*\"r\"*:*,*") &&
		ft_check_int(check, "*\"r\"*:*,*", &check->color_r) == NO_ERROR)
	{
		current->mdiffuse.r = check->color_r;
		ft_normalize_color(&current->mdiffuse);
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"g\"*:*,*") &&
		ft_check_int(check, "*\"g\"*:*,*", &check->color_g) == NO_ERROR)
	{
		current->mdiffuse.g = check->color_g;
		ft_normalize_color(&current->mdiffuse);
		return (NO_ERROR);
	}
	if (ft_match(check->line, "*\"b\"*:*,*") &&
		ft_check_int(check, "*\"b\"*:*,*", &check->color_b) == NO_ERROR)
	{
		current->mdiffuse.b = check->color_b;
		ft_normalize_color(&current->mdiffuse);
		return (NO_ERROR);
	}
	return (ERROR);
}

static int	ft_color_material_p2(t_checkjson *check, t_scene *scene)
{
	t_material	*current;

	current = scene->mmaterials;
	while (current->next != NULL)
		current = current->next;
	return (ft_color_material_p3(check, current));
}

int			ft_color_material(t_checkjson *check, t_scene *scene)
{
	if (check->annonce_color == NOT_DONE)
	{
		if (ft_check_annonce(check, "*\"color\"*",
			&check->annonce_color) == NO_ERROR)
		{
			if (check->annonce_material == MULTI &&
			check->color == DONE)
				if (ft_check_multi_material(check, scene) == ERROR)
					return (ERROR);
			check->color = IN_PROGRE;
			return (NO_ERROR);
		}
		else
			return (ERROR);
	}
	if (ft_color_material_p2(check, scene) == ERROR)
		return (ERROR);
	if (check->nb_curly_bracket < 4)
	{
		ft_re_init_color(check);
		check->color = DONE;
	}
	return (NO_ERROR);
}

int			ft_make_new_material(t_checkjson *check, t_scene *scene)
{
	t_material	*current;
	t_color		color;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	current = scene->mmaterials;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		if ((current->next = ft_new_material(&color)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = current->next;
	}
	else
	{
		if ((scene->mmaterials = ft_new_material(&color)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = scene->mmaterials;
	}
	ft_re_init_material(check);
	return (NO_ERROR);
}
