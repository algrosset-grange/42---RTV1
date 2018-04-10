/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_cylinder_p4.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:45:15 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:45:16 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_check_multi_cylinder(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_cylinder(check, scene) == ERROR)
		return (ERROR);
	check->cylinder = IN_PROGRE;
	check->annonce_cylinder = MULTI;
	return (NO_ERROR);
}

int	ft_make_new_cylinder(t_checkjson *check, t_scene *scene)
{
	t_cylinder	*current;
	t_vector	origin;
	t_vector	direction;

	ft_vect_new_vect(&origin, 0.0, 0.0, 0.0);
	ft_vect_new_vect(&direction, 0.0, 1.0, 0.0);
	current = scene->mcylinders;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		if ((current->next = ft_new_cylinder(&origin, &direction, 10.0,
			scene->material_default)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = current->next;
	}
	else
	{
		if ((scene->mcylinders = ft_new_cylinder(&origin, &direction, 10.0,
			scene->material_default)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = scene->mcylinders;
	}
	ft_re_init_cylinder(check);
	return (NO_ERROR);
}

int	ft_check_add_mat_cylinder(t_checkjson *check, t_scene *scene)
{
	int			c_mat;
	t_cylinder	*current;
	t_material	*current_mat;

	if (check->mat == DONE && check->annonce_cylinder == MULTI)
		if (ft_check_multi_cylinder(check, scene) == ERROR)
			return (ERROR);
	if (check->num_mat >= 0)
	{
		current = scene->mcylinders;
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

int	ft_radius_cylinder(t_checkjson *check, t_scene *scene)
{
	t_cylinder	*current;

	if (check->radius == DONE && check->annonce_cylinder == MULTI)
		if (ft_check_multi_cylinder(check, scene) == ERROR)
			return (ERROR);
	current = scene->mcylinders;
	while (current->next != NULL)
		current = current->next;
	current->mradius = check->size_radius;
	return (NO_ERROR);
}
