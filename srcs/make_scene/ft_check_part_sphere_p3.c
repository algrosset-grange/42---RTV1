/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_part_sphere_p3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:03:33 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 14:03:34 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_check_multi_sphere(t_checkjson *check, t_scene *scene)
{
	if (ft_make_new_sphere(check, scene) == ERROR)
		return (ERROR);
	check->sphere = IN_PROGRE;
	check->annonce_sphere = MULTI;
	return (NO_ERROR);
}

int	ft_make_new_sphere(t_checkjson *check, t_scene *scene)
{
	t_sphere	*current;
	t_vector	vec;

	ft_vect_new_vect(&vec, 0.0, 0.0, 0.0);
	current = scene->mspheres;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		if ((current->next = ft_new_sphere(&vec, 10.0,
			scene->material_default)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = current->next;
	}
	else
	{
		if ((scene->mspheres = ft_new_sphere(&vec, 10.0,
			scene->material_default)) == NULL)
			return (ft_check_error(check, ERROR_MALLOC));
		current = scene->mspheres;
	}
	ft_re_init_sphere(check);
	return (NO_ERROR);
}

int	ft_check_add_mat_sphere(t_checkjson *check, t_scene *scene)
{
	int			c_mat;
	t_sphere	*current;
	t_material	*current_mat;

	if (check->mat == DONE && check->annonce_sphere == MULTI)
		if (ft_check_multi_sphere(check, scene) == ERROR)
			return (ERROR);
	if (check->num_mat >= 0)
	{
		current = scene->mspheres;
		while (current->next != NULL)
			current = current->next;
		current_mat = scene->mmaterials;
		c_mat = 0;
		while (c_mat++ < check->num_mat && current_mat->next != NULL)
			current_mat = current_mat->next;
		if (check->num_mat != c_mat - 1)
			ft_putstr("not the good matierial\n");
		current->mmaterial = current_mat;
	}
	return (NO_ERROR);
}

int	ft_radius_sphere(t_checkjson *check, t_scene *scene)
{
	t_sphere	*current;

	if (check->radius == DONE && check->annonce_sphere == MULTI)
		if (ft_check_multi_sphere(check, scene) == ERROR)
			return (ERROR);
	current = scene->mspheres;
	while (current->next != NULL)
		current = current->next;
	current->mradius = check->size_radius;
	return (NO_ERROR);
}
