/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scene_info_p2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:29:13 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:29:14 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_get_plane_info(t_plane *current)
{
	int		nu;
	char	*tmp;

	nu = 0;
	ft_putstr("\t plane :\n");
	while (current != NULL)
	{
		ft_putstr("\t\t numéro = ");
		tmp = ft_itoa(nu);
		ft_putstr(tmp);
		ft_memdel((void **)&tmp);
		ft_putstr("\n\t\t origin :\n");
		ft_putstr_vector(&current->origin);
		ft_putstr("\n\t\t direction :\n");
		ft_putstr_vector(&current->direction);
		ft_putstr("\n\t\t rotation :\n");
		ft_putstr_vector(&current->rotation);
		ft_putstr("\n\t\t current->mmaterial->mdiffuse :\n");
		ft_putstr_color(&current->mmaterial->mdiffuse);
		current = current->next;
		nu++;
	}
}

static void	ft_get_cylinder_info(t_cylinder *current)
{
	int		nu;
	char	*tmp;

	nu = 0;
	ft_putstr("\t cylinder :\n");
	while (current != NULL)
	{
		ft_putstr("\t\t numéro = ");
		tmp = ft_itoa(nu++);
		ft_putstr(tmp);
		ft_memdel((void **)&tmp);
		ft_putstr("\n\t\t origin :\n");
		ft_putstr_vector(&current->origin);
		ft_putstr("\n\t\t direction :\n");
		ft_putstr_vector(&current->direction);
		ft_putstr("\n\t\t rotation :\n");
		ft_putstr_vector(&current->rotation);
		ft_putstr("\n\t\t mradius = ");
		tmp = ft_dtoa(current->mradius);
		ft_putstr(tmp);
		ft_memdel((void **)&tmp);
		ft_putstr("\n\t\t current->mmaterial->mdiffuse :\n");
		ft_putstr_color(&current->mmaterial->mdiffuse);
		current = current->next;
	}
}

static void	ft_get_cone_info(t_cone *current)
{
	int		nu;
	char	*tmp;

	nu = 0;
	ft_putstr("\t cone :\n");
	while (current != NULL)
	{
		ft_putstr("\t\t numéro =");
		tmp = ft_itoa(nu++);
		ft_putstr(tmp);
		ft_memdel((void **)&tmp);
		ft_putstr("\n\t\t origin :\n");
		ft_putstr_vector(&current->origin);
		ft_putstr("\n\t\t direction :\n");
		ft_putstr_vector(&current->direction);
		ft_putstr("\n\t\t rotation :\n");
		ft_putstr_vector(&current->rotation);
		ft_putstr("\n\t\t mradius = ");
		tmp = ft_dtoa(current->mradius);
		ft_putstr(tmp);
		ft_memdel((void **)&tmp);
		ft_putstr("\n\t\t current->mmaterial->mdiffuse :\n");
		ft_putstr_color(&current->mmaterial->mdiffuse);
		current = current->next;
	}
}

static void	ft_get_sphere_info(t_sphere *current)
{
	int		nu;
	char	*tmp;

	nu = 0;
	ft_putstr("\t sphere : \n");
	while (current != NULL)
	{
		ft_putstr("\t\t numéro = ");
		tmp = ft_itoa(nu++);
		ft_putstr(tmp);
		ft_memdel((void **)&tmp);
		ft_putstr("\n\t\t origin :\n");
		ft_putstr_vector(&current->origin);
		ft_putstr("\n\t\t mradius = ");
		tmp = ft_dtoa(current->mradius);
		ft_putstr(tmp);
		ft_memdel((void **)&tmp);
		ft_putstr("\n\t\t current->mmaterial->mdiffuse :\n");
		ft_putstr_color(&current->mmaterial->mdiffuse);
		current = current->next;
		nu++;
	}
}

void		ft_get_scene_info_p3(t_scene *scene)
{
	ft_get_sphere_info(scene->mspheres);
	ft_get_plane_info(scene->mplanes);
	ft_get_cone_info(scene->mcones);
	ft_get_cylinder_info(scene->mcylinders);
}
