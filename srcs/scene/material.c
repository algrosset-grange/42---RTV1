/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:17:46 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/23 18:17:47 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_material	*ft_n_material(void)
{
	t_material	*new_mater;

	if ((new_mater = ft_memalloc(sizeof(t_material))) == NULL)
		return (NULL);
	new_mater->next = NULL;
	ft_color_n_color(&new_mater->mdiffuse);
	return (new_mater);
}

t_material	*ft_new_material(t_color *color)
{
	t_material	*new_mater;

	if ((new_mater = ft_memalloc(sizeof(t_material))) == NULL)
		return (NULL);
	new_mater->next = NULL;
	ft_color_equal_color(&new_mater->mdiffuse,
		color);
	return (new_mater);
}

void		ft_material_new_material(t_material *mat, t_color *color)
{
	mat->next = NULL;
	ft_color_equal_color(&mat->mdiffuse, color);
}
