/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scene_info_p2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:01:25 by agrosset          #+#    #+#             */
/*   Updated: 2017/08/28 14:48:15 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_get_mat_info(t_material *current)
{
	int		nu;
	char	*tmp;

	nu = 0;
	ft_putstr("\t material :\n");
	while (current != NULL)
	{
		ft_putstr("\t\t numéro = ");
		tmp = ft_itoa(nu);
		ft_putstr(tmp);
		ft_memdel((void **)&tmp);
		ft_putstr("\n\t\t current->mdiffuse :\n");
		ft_putstr_color(&current->mdiffuse);
		current = current->next;
		nu++;
	}
}

static void	ft_get_light_info(t_light *current)
{
	int		nu;
	char	*tmp;

	nu = 0;
	ft_putstr("\t light :\n");
	while (current != NULL)
	{
		ft_putstr("\t\t numéro = ");
		tmp = ft_itoa(nu);
		ft_putstr(tmp);
		ft_memdel((void **)&tmp);
		ft_putstr("\n\t\t current->origin :\n");
		ft_putstr_vector(&current->origin);
		ft_putstr("\n\t\t current->color :\n");
		ft_putstr_color(&current->mcolor);
		current = current->next;
		nu++;
	}
}

void		ft_get_scene_info_p2(t_scene *scene)
{
	ft_putstr("material default : \n");
	ft_get_mat_info(scene->material_default);
	ft_putstr("material creer : \n");
	ft_get_mat_info(scene->mmaterials);
	ft_get_light_info(scene->mlights);
}
