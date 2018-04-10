/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_cone_p4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:58:31 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:58:32 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_check_multi_cone(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_cone(check, scene) == ERROR)
		return (ERROR);
	check->cone = IN_PROGRE;
	check->annonce_cone = MULTI;
	return (NO_ERROR);
}

int	ft_make_new_cone(t_checkjson *check, t_scene *scene)
{
	t_cone		*current;
	t_vector	origin;
	t_vector	direction;

	ft_vect_new_vect(&origin, 0.0, 0.0, 0.0);
	ft_vect_new_vect(&direction, 0.0, 1.0, 0.0);
	current = scene->mcones;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		if ((current->next = ft_new_cone(&origin, &direction, 10.0,
			scene->material_default)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = current->next;
	}
	else
	{
		if ((scene->mcones = ft_new_cone(&origin, &direction, 10.0,
			scene->material_default)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = scene->mcones;
	}
	ft_re_init_cone(check);
	return (NO_ERROR);
}

int	ft_check_add_mat_cone(t_checkjson *check, t_scene *scene)
{
	int			c_mat;
	t_cone		*current;
	t_material	*current_mat;

	if (check->mat == DONE && check->annonce_cone == MULTI)
		if (ft_check_multi_cone(check, scene) == ERROR)
			return (ERROR);
	if (check->num_mat >= 0)
	{
		current = scene->mcones;
		while (current->next != NULL)
			current = current->next;
		current_mat = scene->mmaterials;
		c_mat = 0;
		while (c_mat++ < check->num_mat && current_mat->next != NULL)
			current_mat = current_mat->next;
		if (check->num_mat != c_mat - 1)
			ft_putstr("not the good matierial");
		current->mmaterial = current_mat;
	}
	return (NO_ERROR);
}

int	ft_radius_cone(t_checkjson *check, t_scene *scene)
{
	t_cone	*current;

	if (check->radius == DONE && check->annonce_cone == MULTI)
		if (ft_check_multi_cone(check, scene) == ERROR)
			return (ERROR);
	current = scene->mcones;
	while (current->next != NULL)
		current = current->next;
	current->mradius = (check->size_radius * M_PI) / 180;
	return (NO_ERROR);
}
